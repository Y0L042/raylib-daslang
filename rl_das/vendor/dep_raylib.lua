local utils = require "utils"
local dep_raylib = {}
local name = "RAYLIB"

local repo = "https://github.com/raysan5/raylib"
local version = "5.5"
local folder = "raylib"

function dep_raylib.build()
    print("START: " .. name)

    -- Clone/Update Repo
    if not os.isdir(folder) then
        print("\t\tClone")
        utils.runCommand("git clone --recursive " .. repo .. " " .. folder)
        utils.runCommand("cd " .. folder .. " && git checkout v" .. version .. "")
    else
        print("\t\tFetch")
        utils.changeDir(folder)

        utils.runCommand("git stash")
        utils.runCommand("git pull")
        utils.runCommand("git checkout v" .. version .. "")

        utils.popDir()
    end
    print(name .. " downloaded.")

    -- Build static lib
    utils.pushDir(folder)

    local cmake_flags = "-DCMAKE_BUILD_TYPE=Debug"
        .. " -DBUILD_SHARED_LIBS=OFF"
        .. " -DBUILD_EXAMPLES=OFF"
        .. " -DBUILD_GAMES=OFF"

    if os.target() == "windows" then
        cmake_flags = cmake_flags
            .. ' -DCMAKE_MSVC_RUNTIME_LIBRARY="MultiThreadedDebug"'
    end

    if os.isdir("build") then
        if os.target() == "windows" then
            utils.runCommand("rmdir /s /q build")
        else
            utils.runCommand("rm -rf build")
        end
    end

    print("\t\tConfiguring with: " .. cmake_flags)
    utils.runCommand("cmake -S . -B build " .. cmake_flags)
    utils.runCommand("cmake --build build --config Debug")

    utils.popDir()
    print("END: " .. name)
end

return dep_raylib
