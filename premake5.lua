dofile "configs.lua"

function prependRoot(root, dirs)
    local result = {}
    for _, dir in ipairs(dirs) do
        table.insert(result, root .. "/" .. dir)
    end
    return result
end

workspace "raylib-daslang"
    architecture "x64"
    startproject "rl_das"

    configurations { "Debug", "Release" }
    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    staticruntime "On"

    IncludeDir = {}
    IncludeDir["raylib"]  = "rl_das/vendor/raylib/build/raylib/include"
    IncludeDir["daslang"] = "rl_das/vendor/daslang/include"

    dofile "rl_das/vendor/dependencies.lua"

    include "rl_das"
    include "rl_das_tests"
