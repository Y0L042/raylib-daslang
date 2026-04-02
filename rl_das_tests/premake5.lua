project "rl_das_tests"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    targetdir ("%{wks.location}/tests/bin/" .. outputdir .. "/%{prj.name}")
    objdir    ("%{wks.location}/tests/bin-int/" .. outputdir .. "/%{prj.name}")

    files { "src/**.h", "src/**.cpp" }

    includedirs {
        "src",
        "%{wks.location}/rl_das/src",
    }

    externalincludedirs {
        "%{wks.location}/rl_das/vendor/raylib/build/raylib/include",
        "%{wks.location}/rl_das/vendor/daslang/include",
    }

    defines {
        "DAS_SMART_PTR_DEBUG=1",
        "DAS_ENABLE_DYN_INCLUDES=1",
        "DAS_ENABLE_EXCEPTIONS=1",
    }

    links {
        "rl_das",
        "winmm.lib"
        
    }

    libdirs {
        "%{wks.location}/rl_das/bin/" .. outputdir .. "/rl_das",
        "%{wks.location}/rl_das/vendor/raylib/build/raylib/Debug",
        "%{wks.location}/rl_das/vendor/daslang/lib/Debug",
    }

    filter "action:vs*"
        buildoptions { 
            "/utf-8", 
            '/Zc:__cplusplus', 
            '/Zc:preprocessor' ,
            '/bigobj'
        }
        multiprocessorcompile "On"
    filter {}

    filter "configurations:Debug"
        symbols "On"
        optimize "Off"
        links {
            "libDaScript.lib",
            "libUriParser.lib",
        }
        libdirs {
            "%{wks.location}/rl_das/vendor/raylib/build/raylib/Debug",
            "%{wks.location}/rl_das/vendor/daslang/lib/Debug",
        }

    filter "configurations:Release"
        optimize "Speed"
        symbols "Off"
        links {
            "libDaScript.lib",
            "libUriParser.lib",
        }
        libdirs {
            "%{wks.location}/rl_das/vendor/raylib/build/raylib/Release",
            "%{wks.location}/rl_das/vendor/daslang/lib/Release",
        }
