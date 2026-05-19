cmake_minimum_required(VERSION 3.16)
project(dasModuleRaylib CXX)

# ── Required inputs ────────────────────────────────────────────────────────────
# DASLANG_DIR  — root of a daslang SDK (must contain include/ and lib/)
# RAYLIB_DIR   — root of a raylib installation built as shared (include/ and lib/)
#
# Build example (Windows, Release):
#   cmake -S . -B _build -DDASLANG_DIR=C:/path/to/daslang -DRAYLIB_DIR=C:/path/to/raylib
#   cmake --build _build --config Release
# ──────────────────────────────────────────────────────────────────────────────

if(NOT DEFINED DASLANG_DIR)
    message(FATAL_ERROR "DASLANG_DIR must be set to the daslang SDK root (contains include/ and lib/)")
endif()

if(NOT DEFINED RAYLIB_DIR)
    message(FATAL_ERROR "RAYLIB_DIR must be set to a raylib installation with shared libs (contains include/ and lib/)")
endif()

# ── Source files ───────────────────────────────────────────────────────────────
# The generated .inc files are #included directly by module_raylib.cpp.
add_library(dasModuleRaylib SHARED
    rl_das/src/module_raylib.cpp
)

target_compile_features(dasModuleRaylib PRIVATE cxx_std_17)

target_compile_definitions(dasModuleRaylib PRIVATE
    DAS_MOD_EXPORTS
    DAS_ENABLE_DLL=1
    DAS_ENABLE_EXCEPTIONS=1
    $<$<CONFIG:Release>:DAS_NO_ASSERTIONS>
    $<$<CONFIG:MinSizeRel>:DAS_NO_ASSERTIONS>
    $<$<CONFIG:RelWithDebInfo>:DAS_NO_ASSERTIONS>
)

target_include_directories(dasModuleRaylib PRIVATE
    rl_das/src
    "${DASLANG_DIR}/include"
    "${RAYLIB_DIR}/include"
)

# ── Locate daslang dynamic libs ───────────────────────────────────────────────
# Probe config-subdirs first (Release, Debug), then flat layout (installed SDK).
foreach(_cfg Release Debug)
    if(EXISTS "${DASLANG_DIR}/lib/${_cfg}/libDaScriptDyn.lib")
        set(_DAS_LIB_DIR "${DASLANG_DIR}/lib/${_cfg}")
        break()
    endif()
endforeach()
if(NOT DEFINED _DAS_LIB_DIR)
    set(_DAS_LIB_DIR "${DASLANG_DIR}/lib")
endif()
message(STATUS "daslang libs: ${_DAS_LIB_DIR}")

# ── Locate raylib shared lib ──────────────────────────────────────────────────
# MSVC cmake builds output to a Release/ or Debug/ config subdir.
# MinGW builds produce libraylib.dll directly (no separate import lib).
foreach(_candidate
        "${RAYLIB_DIR}/Release/raylib.lib"
        "${RAYLIB_DIR}/Debug/raylib.lib"
        "${RAYLIB_DIR}/lib/raylib.lib"
        "${RAYLIB_DIR}/lib/Release/raylib.lib"
        "${RAYLIB_DIR}/lib/Debug/raylib.lib"
        "${RAYLIB_DIR}/libraylib.dll"
        "${RAYLIB_DIR}/lib/libraylib.dll.a"
)
    if(EXISTS "${_candidate}")
        set(_RAYLIB_LIB "${_candidate}")
        break()
    endif()
endforeach()
if(NOT DEFINED _RAYLIB_LIB)
    message(FATAL_ERROR "Could not find raylib import lib under RAYLIB_DIR=${RAYLIB_DIR}")
endif()
message(STATUS "raylib lib: ${_RAYLIB_LIB}")

# ── Platform-specific linking ──────────────────────────────────────────────────
if(WIN32)
    target_link_libraries(dasModuleRaylib PRIVATE
        "${_DAS_LIB_DIR}/libDaScriptDyn.lib"
        "${_DAS_LIB_DIR}/libDaScriptDyn_runtime.lib"
        "${_RAYLIB_LIB}"
    )
elseif(APPLE)
    target_link_libraries(dasModuleRaylib PRIVATE
        "${_DAS_LIB_DIR}/libDaScriptDyn.dylib"
        "${_DAS_LIB_DIR}/libDaScriptDyn_runtime.dylib"
        "${RAYLIB_DIR}/lib/libraylib.dylib"
    )
else()
    target_link_libraries(dasModuleRaylib PRIVATE
        "${_DAS_LIB_DIR}/libDaScriptDyn.so"
        "${_DAS_LIB_DIR}/libDaScriptDyn_runtime.so"
        "${RAYLIB_DIR}/lib/libraylib.so"
    )
endif()

if(MSVC)
    target_compile_options(dasModuleRaylib PRIVATE
        /utf-8
        /Zc:__cplusplus
        /Zc:preprocessor
        /bigobj
        /wd4005
        /MP
    )
endif()

# ── Output naming ──────────────────────────────────────────────────────────────
set_target_properties(dasModuleRaylib PROPERTIES
    SUFFIX ".shared_module"
    PREFIX ""
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}"
    RUNTIME_OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}"
    LIBRARY_OUTPUT_DIRECTORY         "${CMAKE_CURRENT_SOURCE_DIR}"
)

# ── Copy raylib shared lib next to the .shared_module ─────────────────────────
if(WIN32)
    # Probe for the DLL — mirrors the import-lib search order above.
    foreach(_candidate
            "${RAYLIB_DIR}/Release/raylib.dll"
            "${RAYLIB_DIR}/Debug/raylib.dll"
            "${RAYLIB_DIR}/bin/raylib.dll"
            "${RAYLIB_DIR}/libraylib.dll"
            "${RAYLIB_DIR}/raylib.dll"
    )
        if(EXISTS "${_candidate}")
            set(_RAYLIB_DLL "${_candidate}")
            break()
        endif()
    endforeach()
    if(NOT DEFINED _RAYLIB_DLL)
        message(FATAL_ERROR "Could not find raylib.dll under RAYLIB_DIR=${RAYLIB_DIR}")
    endif()
    add_custom_command(TARGET dasModuleRaylib POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${_RAYLIB_DLL}"
            "${CMAKE_CURRENT_SOURCE_DIR}/libraylib.dll"
        COMMENT "Copying libraylib.dll alongside dasModuleRaylib.shared_module"
    )
elseif(APPLE)
    add_custom_command(TARGET dasModuleRaylib POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${RAYLIB_DIR}/lib/libraylib.dylib"
            "${CMAKE_CURRENT_SOURCE_DIR}/libraylib.dylib"
        COMMENT "Copying libraylib.dylib alongside dasModuleRaylib.shared_module"
    )
else()
    add_custom_command(TARGET dasModuleRaylib POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${RAYLIB_DIR}/lib/libraylib.so"
            "${CMAKE_CURRENT_SOURCE_DIR}/libraylib.so"
        COMMENT "Copying libraylib.so alongside dasModuleRaylib.shared_module"
    )
endif()
