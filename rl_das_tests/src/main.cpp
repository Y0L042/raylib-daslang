#include <iostream>
#include <sstream>
#include <string>
#include <memory>

#include <daScript/daScript.h>
#include <rl_das.h>

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

    RunDasScript(libGroup, scriptsDir + "sandbox.das", "sandbox");

    das::Module::Shutdown();

    return 0;
}
