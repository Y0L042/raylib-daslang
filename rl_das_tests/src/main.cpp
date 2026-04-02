#include <iostream>
#include <sstream>
#include <string>
#include <memory>
#include <atomic>

#include <daScript/daScript.h>
#include <rl_das.h>

#include "FileWatch.h"

std::string GetScriptsDir()
{
    std::string file_path(__FILE__);
    size_t pos = file_path.find("rl_das_tests");
    if (pos != std::string::npos)
    {
        return file_path.substr(0, pos) + "rl_das_tests/scripts/";
    }
    return "scripts/";
}

std::string SafeErrorReport(const das::Error &err)
{
    std::ostringstream oss;
    oss << "\n";
    oss << "What:  " << err.what << "\n";
    oss << "Extra: " << err.extra << "\n";
    oss << "Fixme: " << err.fixme << "\n";
    if (err.at.fileInfo != nullptr)
    {
        try
        {
            oss << "At: " << err.at.describe() << "\n";
        }
        catch (...)
        {
            oss << "At: <describe() threw>\n";
        }
    }
    else
    {
        oss << "At: " << err.at.line << ":" << err.at.column << " <no file>\n";
    }
    oss << "Cerr: " << (int)err.cerr << "\n";
    return oss.str();
}

bool RunDasScript(das::ModuleGroup &libGroup, const std::string &scriptPath, const std::string &exportedFn)
{
    das::TextPrinter tout;

    auto fileAccess = das::make_smart<das::FsFileAccess>();

    das::CodeOfPolicies policies;
    policies.rtti = true;

    std::cout << "  Compiling " << scriptPath << " ...\n";
    das::ProgramPtr program = das::compileDaScript(scriptPath, fileAccess, tout, libGroup, policies);
    if (program->failed())
    {
        std::cerr << "  Compilation FAILED:\n";
        for (auto &err : program->errors)
            std::cerr << SafeErrorReport(err);
        return false;
    }

    das::Context context(program->getContextStackSize());
    if (!program->simulate(context, tout))
    {
        std::cerr << "  Simulation FAILED:\n";
        for (auto &err : program->errors)
            std::cerr << SafeErrorReport(err);
        return false;
    }

    das::SimFunction *fn = context.findFunction(exportedFn.c_str());
    if (!fn)
    {
        std::cerr << "  ERROR: exported function '" << exportedFn << "' not found.\n";
        return false;
    }

    context.evalWithCatch(fn, nullptr, nullptr);
    if (auto ex = context.getException())
    {
        std::cerr << "  Script exception: " << ex << "\n";
        return false;
    }

    return true;
}

bool RunHotDasScript(das::ModuleGroup &libGroup, const std::string &scriptPath, const std::string &exportedFn,
                     const std::string &exportedHotLoopFn, const std::string &exportedShutdownFn)
{
    const std::size_t lastSlash = scriptPath.find_last_of("/\\");
    const std::string scriptsDir = (lastSlash != std::string::npos) ? scriptPath.substr(0, lastSlash + 1) : std::string();

    std::atomic_bool recompileRequested{false};

    std::wregex wrgx(L".*\\.das$");
    std::wstring wpath(scriptsDir.begin(), scriptsDir.end());
    auto directoryWatch = std::make_unique<filewatch::FileWatch<std::wstring>>(
        wpath, wrgx, [&recompileRequested](const std::wstring &, const filewatch::Event) {
            recompileRequested.store(true, std::memory_order_release);
        });

    das::ProgramPtr program;
    std::unique_ptr<das::Context> context;
    das::SimFunction *setupFn = nullptr;
    das::SimFunction *loopFn = nullptr;
    das::SimFunction *shutdownFn = nullptr;

    auto compileAndBind = [&](das::ProgramPtr &outProgram,
                              std::unique_ptr<das::Context> &outContext,
                              das::SimFunction *&outSetupFn,
                              das::SimFunction *&outLoopFn,
                              das::SimFunction *&outShutdownFn) -> bool {
        das::TextPrinter tout;
        auto fileAccess = das::make_smart<das::FsFileAccess>();

        das::CodeOfPolicies policies;
        policies.rtti = true;

        std::cout << "  Compiling " << scriptPath << " ...\n";
        outProgram = das::compileDaScript(scriptPath, fileAccess, tout, libGroup, policies);
        if (outProgram->failed())
        {
            std::cerr << "  Compilation FAILED:\n";
            for (auto &err : outProgram->errors)
                std::cerr << SafeErrorReport(err);
            return false;
        }

        auto newContext = std::make_unique<das::Context>(outProgram->getContextStackSize());
        if (!outProgram->simulate(*newContext, tout))
        {
            std::cerr << "  Simulation FAILED:\n";
            for (auto &err : outProgram->errors)
                std::cerr << SafeErrorReport(err);
            return false;
        }

        outSetupFn = newContext->findFunction(exportedFn.c_str());
        if (!outSetupFn)
        {
            std::cerr << "  ERROR: exported function '" << exportedFn << "' not found.\n";
            return false;
        }

        outLoopFn = newContext->findFunction(exportedHotLoopFn.c_str());
        if (!outLoopFn)
        {
            std::cerr << "  ERROR: exported function '" << exportedHotLoopFn << "' not found.\n";
            return false;
        }

        outShutdownFn = newContext->findFunction(exportedShutdownFn.c_str());
        if (!outShutdownFn)
        {
            std::cerr << "  ERROR: exported function '" << exportedShutdownFn << "' not found.\n";
            return false;
        }

        outContext = std::move(newContext);
        return true;
    };

    if (!compileAndBind(program, context, setupFn, loopFn, shutdownFn))
    {
        return false;
    }

    context->evalWithCatch(setupFn, nullptr, nullptr);
    if (auto ex = context->getException())
    {
        std::cerr << "  Script exception: " << ex << "\n";
        return false;
    }

    while (true)
    {
        while (!recompileRequested.load(std::memory_order_acquire))
        {
            context->evalWithCatch(loopFn, nullptr, nullptr);
            if (auto ex = context->getException())
            {
                std::cerr << "  Script exception: " << ex << "\n";
                return false;
            }
        }

        recompileRequested.store(false, std::memory_order_release);

        das::ProgramPtr newProgram;
        std::unique_ptr<das::Context> newContext;
        das::SimFunction *newSetupFn = nullptr;
        das::SimFunction *newLoopFn = nullptr;
        das::SimFunction *newShutdownFn = nullptr;

        if (!compileAndBind(newProgram, newContext, newSetupFn, newLoopFn, newShutdownFn))
        {
            std::cout << "  Recompile failed, keeping previous program running.\n";
            continue;
        }

        context->evalWithCatch(shutdownFn, nullptr, nullptr);
        if (auto ex = context->getException())
        {
            std::cerr << "  Script exception: " << ex << "\n";
            return false;
        }

        program = std::move(newProgram);
        context = std::move(newContext);
        setupFn = newSetupFn;
        loopFn = newLoopFn;
        shutdownFn = newShutdownFn;

        context->evalWithCatch(setupFn, nullptr, nullptr);
        if (auto ex = context->getException())
        {
            std::cerr << "  Script exception: " << ex << "\n";
            return false;
        }

        std::cout << "  Recompile successful.\n";
    }

    return true;
}

int main(int argc, char *argv[])
{
    std::cout << "rl_das_tests - Testing the raylib daScript module\n\n";

    NEED_ALL_DEFAULT_MODULES;
    NEED_MODULE(Module_raylib);
    das::Module::Initialize();

    das::ModuleGroup libGroup;

    const std::string scriptsDir = GetScriptsDir();

    // std::cout << "[ RUN ] Raylib Test Suite\n";
    // if (RunDasScript(libGroup, scriptsDir + "test_all.das", "main"))
    // {
    //     std::cout << "[ PASS ] Raylib Test Suite\n\n";
    // }
    // else
    // {
    //     std::cout << "[ FAIL ] Raylib Test Suite\n\n";
    // }

    if (!RunHotDasScript(libGroup, scriptsDir + "sandbox.das", "hot_recompile", "hot_recompile_loop",
                         "hot_recompile_shutdown"))
    {
        std::cout << "RunHotDasScript() returned false!\n";
    }

    das::Module::Shutdown();

    return 0;
}
