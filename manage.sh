#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PYTHON="py -3.13"
GENERATE_XXD="$SCRIPT_DIR/rl_das/tools/generate_xxd.py"
DASLANG="$SCRIPT_DIR/rl_das/vendor/daslang/build/Debug/daslang.exe"
SCRIPT_INC="$SCRIPT_DIR/rl_das/src"
DAS_FORMATTER="$SCRIPT_DIR/rl_das/vendor/daslang/utils/dasCodeFormatter/main.das"
DASROOT="$SCRIPT_DIR/rl_das/vendor/daslang"

GEN_RAYLIB_BIND_PY="$SCRIPT_DIR/rl_das/tools/gen_raylib_bindings.py"
RAYLIB_H="${RAYLIB_DIR}/include/raylib.h"
GENERATED_DIR="$SCRIPT_DIR/rl_das/src/generated"
RAYLIB_DAS_SCRIPTS="$SCRIPT_DIR/rl_das/src/scripts"

usage() {
    echo "Usage: $0 <command> [args]"
    echo ""
    echo "Commands:"
    echo "  gen-raylib-bind              Parse raylib.h and generate C++ binding .inc files into src/generated/"
    echo "  gen-inc                      Regenerate all .das.inc files from their .das sources"
    echo "  fmt <file.das>               Format a .das file in-place (backs up, formats, verifies)"
    echo "  fmt-all                      Format all .das files under rl_das/src"
    echo "  codegen                      Run the full pipeline: gen-raylib-bind, gen-inc"
    echo "  build-module                 Build dasModuleRaylib.shared_module"
    echo "                               Uses \$DASLANG_DIR and \$RAYLIB_DIR from environment"
    echo "  help                         Show this help message"
}

cmd_gen_inc() {
    local script_dir="$SCRIPT_DIR/rl_das/src/scripts"
    local count=0

    while IFS= read -r -d '' das_file; do
        local inc_file="${das_file}.inc"
        echo "  ${das_file##*/} -> ${inc_file##*/}"
        $PYTHON "$GENERATE_XXD" "$das_file" "$inc_file"
        (( count++ )) || true
    done < <(find "$script_dir" -name "*.das" -print0)

    echo "Generated $count file(s)."
}

cmd_fmt() {
    local das_file="${1:-}"
    if [[ -z "$das_file" ]]; then
        echo "Usage: $0 fmt <file.das>"
        exit 1
    fi
    local bak="${das_file}.bak"
    echo "  Formatting ${das_file##*/}..."
    cp "$das_file" "$bak"
    if "$DASLANG" -dasroot "$DASROOT" "$DAS_FORMATTER" -- "$das_file"; then
        rm -f "$bak"
        echo "  Done."
    else
        echo "  Formatter failed — restoring backup."
        cp "$bak" "$das_file"
        rm -f "$bak"
        exit 1
    fi
}

cmd_fmt_all() {
    local script_dir="$SCRIPT_DIR/rl_das/src"
    local count=0

    while IFS= read -r -d '' das_file; do
        cmd_fmt "$das_file"
        (( count++ )) || true
    done < <(find "$script_dir" -name "*.das" -print0)

    echo "Formatted $count file(s)."
}

cmd_gen_raylib_bind() {
    if [[ -z "${RAYLIB_DIR:-}" ]]; then
        echo "ERROR: RAYLIB_DIR is not set"
        exit 1
    fi
    if [[ ! -f "$RAYLIB_H" ]]; then
        echo "ERROR: raylib.h not found at $RAYLIB_H"
        echo "Check that RAYLIB_DIR points to a built raylib installation (e.g. C:/Projects/C_Libs/raylib/build/shared/raylib)"
        exit 1
    fi

    echo "Parsing raylib.h and generating C++ binding .inc files..."
    $PYTHON "$GEN_RAYLIB_BIND_PY" "$RAYLIB_H" "$GENERATED_DIR"
}

cmd_codegen() {
    echo "==> gen-raylib-bind"
    cmd_gen_raylib_bind
    echo "==> gen-inc"
    cmd_gen_inc
}

cmd_build_module() {
    if [[ -z "${DASLANG_DIR:-}" ]]; then
        echo "ERROR: DASLANG_DIR is not set"
        exit 1
    fi
    if [[ -z "${RAYLIB_DIR:-}" ]]; then
        echo "ERROR: RAYLIB_DIR is not set"
        exit 1
    fi

    local build_dir="$SCRIPT_DIR/_build"

    echo "==> Configuring (DASLANG_DIR=$DASLANG_DIR, RAYLIB_DIR=$RAYLIB_DIR)"
    cmake -S "$SCRIPT_DIR" -B "$build_dir" \
        -DDASLANG_DIR="$DASLANG_DIR" \
        -DRAYLIB_DIR="$RAYLIB_DIR"

    echo "==> Building"
    cmake --build "$build_dir" --config Release

    echo "==> Done: $SCRIPT_DIR/dasModuleRaylib.shared_module"
}

case "${1:-}" in
    gen-raylib-bind) cmd_gen_raylib_bind ;;
    gen-inc)         cmd_gen_inc ;;
    fmt)             cmd_fmt "${2:-}" ;;
    fmt-all)         cmd_fmt_all ;;
    codegen)         cmd_codegen ;;
    build-module)    cmd_build_module "${2:-}" "${3:-}" ;;
    help|"")         usage ;;
    *)               echo "Unknown command: $1"; usage; exit 1 ;;
esac
