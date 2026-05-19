#!/usr/bin/env python3
"""Generate Daslang bindings for the raylib C API from raylib.h.

Usage:
    python3 gen_raylib_bindings.py <raylib.h> <out_dir>

Outputs:
    <out_dir>/module_raylib_annotations.inc  -- C++ type annotation definitions
    <out_dir>/module_raylib_register.inc     -- C++ constructor registration calls
    <out_dir>/module_raylib_enums.inc        -- C++ enum class defs + DAS_BIND_ENUM_CAST
"""

import re
import sys
import os

# ─── Types already hand-registered in module_raylib.cpp ──────────────────────
# These get MAKE_TYPE_FACTORY + annotations in the .inc file; we skip them for
# the struct section because they are already declared there.
HANDWRITTEN_TYPES = {
    "Vector2", "Vector3", "Vector4", "Quaternion", "Matrix",
    "Color", "Rectangle", "Image", "Texture", "Texture2D",
    "RenderTexture", "RenderTexture2D", "NPatchInfo", "GlyphInfo",
    "Font", "Mesh", "Shader", "Material", "Transform", "BoneInfo",
    "Model", "ModelAnimation", "Ray", "RayCollision", "BoundingBox",
    "Wave", "AudioStream", "Sound", "Music",
}

# Struct types we add in the generator output (not hand-written)
EXTRA_STRUCT_TYPES = {
    "Camera3D", "Camera2D", "VrDeviceInfo", "VrStereoConfig",
    "FilePathList", "AutomationEvent", "AutomationEventList", "ModelSkeleton",
}

# Types that should be emitted to annotations, but not registered in module_raylib.cpp.
REGISTER_EXCLUDED_STRUCT_TYPES = {"Camera3D", "Camera2D"}

ALL_KNOWN_TYPES = HANDWRITTEN_TYPES | EXTRA_STRUCT_TYPES

# C typedef aliases that map to known types
TYPE_ALIASES = {
    "Camera":         "Camera3D",
    "TextureCubemap": "Texture",
    "Quaternion":     "Vector4",
    "RenderTexture2D": "RenderTexture",
    "Texture2D":      "Texture",
    "ModelAnimPose":  None,  # Transform* — skip
}

# Functions to skip (problematic signatures, handled manually, or not useful)
SKIP_FUNCS = {
    # Callback/varargs/complex pointer functions
    "SetTraceLogCallback",
    "SetLoadFileDataCallback",
    "SetSaveFileDataCallback",
    "SetLoadFileTextCallback",
    "SetSaveFileTextCallback",
    # Takes va_list
    "TraceLog",
    # Returns void* (window handle) - too platform-specific
    "GetWindowHandle",
    # Takes void* value with a separate type enum - complex to bind directly
    "SetShaderValue",
    "SetShaderValueV",
    # Automation callbacks
    "SetAudioStreamCallback",
    "AttachAudioStreamProcessor",
    "DetachAudioStreamProcessor",
    "AttachAudioMixedProcessor",
    "DetachAudioMixedProcessor",
    # Takes Image** (double pointer)
    "SetWindowIcons",
    # Takes void* data
    "UpdateTexture",
    "UpdateTextureRec",
    "UpdateMeshBuffer",
    "UploadMesh",
    "DrawMeshInstanced",
    # Takes/returns raw arrays needing special handling
    "LoadImageAnimFromMemory",
    "LoadImageFromMemory",
    "LoadFontFromMemory",
    "LoadFontData",
    "GenImageFontAtlas",
    "LoadModelAnimations",
    "ExportDataAsCode",
    "LoadFileData",
    "SaveFileData",
    "CompressData",
    "DecompressData",
    "EncodeDataBase64",
    "DecodeDataBase64",
    "LoadDirectoryFiles",
    "LoadDirectoryFilesEx",
    "GetDroppedFiles",
    "LoadAutomationEventList",
    "UnloadAutomationEventList",
    "SetAutomationEventList",
    "SetAutomationEventBaseFrame",
    "StartAutomationEventRecording",
    "StopAutomationEventRecording",
    "PlayAutomationEvent",
    "ExportAutomationEventList",
    # Takes/returns structs by value that need binding wrappers
    "ClearBackground",
    "BeginMode2D",
    "BeginMode3D",
    "BeginTextureMode",
    "BeginShaderMode",
    "DrawPixel",
    "DrawLine",
    "DrawLineEx",
    "DrawPointV",
    "DrawCircle",
    "DrawCircleV",
    "DrawCircleGradient",
    "DrawCircleLines",
    "DrawCircleLinesV",
    "DrawRectangle",
    "DrawRectangleV",
    "DrawRectangleRec",
    "DrawRectanglePro",
    "DrawRectangleGradientH",
    "DrawRectangleGradientV",
    "DrawRectangleGradient",
    "DrawRectangleLines",
    "DrawRectangleLinesEx",
    "DrawRectangleRounded",
    "DrawRectangleRoundedLines",
    "DrawTriangle",
    "DrawTriangleLines",
    "DrawTriangleFan",
    "DrawTriangleStrip",
    "DrawPoly",
    "DrawPolyLines",
    "DrawPolyLinesEx",
    "CheckCollisionPointRec",
    "GetImageData",
    "GetImageAlphaBorder",
    "GetImageColor",
    "ImageColorReplace",
    "ImageColorConvolve",
    "ImageColorBrightness",
    "ImageColorContrast",
    "ImageColorGrayscale",
    "ImageKernelConvolution",
    "TextFindIndex",
    "DrawText",
    "DrawTextEx",
    "DrawTextProEx",
    "DrawTextCodepoint",
    "DrawTextCodepoints",
    "GetGlyphIndex",
    "GetGlyphInfo",
    "GetGlyphAtlasRec",
    "MeasureText",
    "MeasureTextEx",
    "DrawCircle3D",
    "DrawTriangle3D",
    "DrawCube",
    "DrawCubeV",
    "DrawCubeWires",
    "DrawCubeWiresV",
    "DrawSphere",
    "DrawSphereEx",
    "DrawSpherewires",
    "DrawCylinder",
    "DrawCylinderEx",
    "DrawCylinderWires",
    "DrawCylinderWiresEx",
    "DrawCone",
    "DrawConeEx",
    "DrawConeWires",
    "DrawConeWiresEx",
    "DrawCube",
    "DrawPlane",
    "DrawRay",
    "DrawGrid",
    "DrawGizmo",
    "DrawBoundingBox",
    "DrawBillboard",
    "DrawBillboardRec",
    "DrawBillboardPro",
    "DrawModel",
    "DrawModelEx",
    "DrawModelWires",
    "DrawModelWiresEx",
    "DrawBoneLink",
    "DrawPoint3D",
    "DrawLine3D",
    "DrawTriangle3D",
    "DrawTriangleStrip3D",
    "DrawCube",
    "DrawCubeV",
    "DrawCubeWires",
    "DrawCubeWiresV",
    "DrawSphere",
    "DrawSphereEx",
    "DrawSphereWires",
    "DrawCylinder",
    "DrawCylinderEx",
    "DrawCylinderWires",
    "DrawCylinderWiresEx",
    "DrawCone",
    "DrawConeEx",
    "DrawConeWires",
    "DrawConeWiresEx",
    "DrawPlane",
    "DrawRay",
    "DrawGrid",
    "DrawBoundingBox",
    "GetImageData",
    "LoadFontEx",
    "UnloadFontData",
    "GetGlyphIndex",
    "GetGlyphInfo",
    "GetGlyphAtlasRec",
    "DrawTextCodepoints",
    "LoadCodepoints",
    "UnloadCodepoints",
    "GetCodepointCount",
    "GetCodepoint",
    "GetCodepointNext",
    "GetCodepointPrevious",
    "CodepointToUTF8",
    "TextJoin",
    "TextSplit",
    "GetMeshBoundingBox",
    "UpdateModelAnimationBones",
    "IsModelAnimationValid",
    "ExportMesh",
    "GenMeshHeightmap",
    "GenMeshCubicmap",
    "UpdateMaterial",
    "SetMaterialTexture",
    "SetModelMeshMaterial",
    "LoadMaterials",
    "LoadSkeleton",
    "UnloadSkeleton",
    "DrawMesh",
}

# C → Daslang primitive type map
C_TO_DAS = {
    "void":           "void",
    "bool":           "bool",
    "char":           "int8",
    "unsigned char":  "uint8",
    "short":          "int16",
    "unsigned short": "uint16",
    "int":            "int",
    "unsigned int":   "uint",
    "long":           "int64",
    "unsigned long":  "uint64",
    "float":          "float",
    "double":         "double",
    "int8_t":         "int8",
    "int16_t":        "int16",
    "int32_t":        "int",
    "int64_t":        "int64",
    "uint8_t":        "uint8",
    "uint16_t":       "uint16",
    "uint32_t":       "uint",
    "uint64_t":       "uint64",
    "size_t":         "uint64",
    "ptrdiff_t":      "int64",
    "const char":     "int8",
}

# Daslang SideEffects category for raylib functions
# Raylib functions always modify GPU/audio/window state
SIDE_EFFECTS = "das::SideEffects::modifyExternal"

# DasLang reserved keywords that need field renaming
DAS_RESERVED_FIELD_RENAMES = {
    "type": "vtype",
    "cast": "vcast",
    "context": "vcontext",
}

# Scalar typedefs from C headers to DasLang
EXTRA_SCALAR_TYPEDEFS = {
    # Add internal/private header types here if discovered
    # Example: "rl_gl_state_t": "uint"
}

# ─── Comment stripping ────────────────────────────────────────────────────────
def strip_comments(text: str) -> str:
    result = []
    i = 0
    n = len(text)
    while i < n:
        if text[i:i+2] == "//":
            while i < n and text[i] != "\n":
                result.append(" ")
                i += 1
        elif text[i:i+2] == "/*":
            result.append(" ")
            i += 2
            while i < n and text[i:i+2] != "*/":
                result.append("\n" if text[i] == "\n" else " ")
                i += 1
            result.append(" ")
            i += 2
        else:
            result.append(text[i])
            i += 1
    return "".join(result)


# ─── Enum parsing ─────────────────────────────────────────────────────────────
def parse_enums(text: str) -> list:
    """Return [(enum_name, [(member_name, value_str_or_None)])] for all typedef enums."""
    results = []
    # Match anonymous and named typedef enums
    pat = re.compile(
        r"typedef\s+enum\s*(?:\w+)?\s*\{([^}]*)\}\s*(\w+)\s*;", re.DOTALL
    )
    for m in pat.finditer(text):
        body = m.group(1)
        enum_name = m.group(2)
        members = []
        for line in body.splitlines():
            line = line.strip().rstrip(",").strip()
            if not line or line.startswith("//") or line.startswith("/*"):
                continue
            # Remove inline comments
            line = re.sub(r"//.*$", "", line).strip().rstrip(",").strip()
            if not line:
                continue
            if "=" in line:
                name_part, val_part = line.split("=", 1)
                name_part = name_part.strip()
                val_part = val_part.strip()
                if re.match(r"^[A-Z_][A-Z0-9_]*$", name_part):
                    members.append((name_part, val_part))
            else:
                if re.match(r"^[A-Z_][A-Z0-9_]*$", line):
                    members.append((line, None))
        if members:
            results.append((enum_name, members))
    return results


# ─── Function parsing ─────────────────────────────────────────────────────────
def parse_type(raw: str) -> dict:
    """Parse a C type string into {base, ptr_depth, is_const, is_ref}."""
    s = raw.strip()
    is_const = "const" in s
    s = re.sub(r"\bconst\b", "", s).strip()
    ptr_depth = s.count("*")
    s = s.replace("*", "").strip()
    s = re.sub(r"\s+", " ", s).strip()
    return {"base": s, "ptr_depth": ptr_depth, "is_const": is_const}


def c_type_to_das(raw: str, is_return: bool = False) -> str | None:
    """
    Convert a C type string to a Daslang type string.
    Returns None if the type cannot be safely auto-bound.
    """
    info = parse_type(raw)
    base = info["base"]
    ptr  = info["ptr_depth"]
    const = info["is_const"]

    # void return
    if base == "void" and ptr == 0:
        return "void"

    # void* — opaque pointer, skip
    if base == "void" and ptr > 0:
        return None

    # const char* → string (daslang string maps to C char*)
    if base == "char" and ptr == 1 and const:
        return "string const+"
    # char* (non-const) → string (mutable, but we accept it as string)
    if base == "char" and ptr == 1 and not const:
        return "string+"

    # double pointer — skip
    if ptr > 1:
        return None

    # Resolve type aliases (Camera → Camera3D, Texture2D → Texture, etc.)
    if base in TYPE_ALIASES:
        resolved = TYPE_ALIASES[base]
        if resolved is None:
            return None
        base = resolved

    # Single pointer to known struct → ref (pass by pointer = pass by ref in daslang)
    if ptr == 1 and base in ALL_KNOWN_TYPES:
        return f"{base}&"

    # Pointer to primitive (e.g. int*, float*) — skip for auto-bind
    if ptr == 1 and base not in ALL_KNOWN_TYPES:
        return None

    # Value type — primitive
    if base in C_TO_DAS:
        return C_TO_DAS[base]

    # Value type — known raylib struct (pass by value)
    if base in ALL_KNOWN_TYPES:
        return base

    # Unknown type
    return None


def parse_params(params_str: str) -> list | None:
    """
    Parse a C function parameter list.
    Returns [(c_type_str, param_name)] or None if unparseable.
    """
    params_str = params_str.strip()
    if params_str in ("", "void"):
        return []

    # Split by comma, but respect parens (for function pointers — we'll reject those)
    parts = []
    depth = 0
    current = []
    for ch in params_str:
        if ch == "(":
            depth += 1
        elif ch == ")":
            depth -= 1
        if ch == "," and depth == 0:
            parts.append("".join(current).strip())
            current = []
        else:
            current.append(ch)
    if current:
        parts.append("".join(current).strip())

    result = []
    for part in parts:
        part = part.strip()
        if not part:
            continue
        # Reject function pointer parameters immediately
        if "(*" in part or "(" in part:
            return None

        # Normalize spaces
        part = re.sub(r"\s+", " ", part)

        # Try to split type and name
        # Handle: "const Type *name", "Type name", "unsigned int count"
        m = re.match(r"^(.*?)\b(\w+)\s*$", part)
        if not m:
            return None
        type_str = m.group(1).strip()
        name = m.group(2)

        # If name is a type keyword (e.g., just "int"), treat whole thing as unnamed
        if not type_str:
            type_str = name
            name = f"p{len(result)}"

        result.append((type_str, name))

    return result


def parse_functions(text: str) -> list:
    """
    Return [{"ret": str, "name": str, "params": [(type, name)]}]
    for all RLAPI declarations.
    """
    # Match: RLAPI <return_type> <name>(<params>);
    # The return type can include spaces (e.g. "unsigned int", "const char *")
    pat = re.compile(
        r"RLAPI\s+((?:const\s+)?(?:unsigned\s+|signed\s+)?\w[\w\s]*?)\s*"
        r"(\*?)\s*(\w+)\s*\(([^)]*)\)\s*;",
        re.MULTILINE
    )
    results = []
    for m in pat.finditer(text):
        ret_base = m.group(1).strip()
        ret_ptr  = m.group(2).strip()
        name     = m.group(3)
        params_str = m.group(4)

        if name in SKIP_FUNCS:
            continue
        if name.startswith("_"):
            continue

        ret_type = ret_base + (" *" if ret_ptr else "")
        params = parse_params(params_str)
        if params is None:
            continue  # has function pointer param, skip

        results.append({"ret": ret_type, "name": name, "params": params})

    return results


# ─── Phase 1: Return type classification ──────────────────────────────────────
def classify_return(ret_c: str, defined_struct_names: set, opaque_struct_names: set) -> str:
    """
    Classify C return type for correct DasLang binding method.
    Returns: 'plain', 'copy_or_move', or 'skip'
    
    - 'plain': void, scalar, pointer, const char* → use DAS_BIND_FUN
    - 'copy_or_move': struct by value (defined, not opaque) → use SimNode_ExtFuncCallAndCopyOrMove
    - 'skip': struct by value (opaque) or other unsafe → not bindable
    """
    info = parse_type(ret_c)
    base = info["base"]
    ptr = info["ptr_depth"]
    
    # void, scalar, or pointer → plain
    if base == "void" or base in C_TO_DAS:
        if base == "void" and ptr > 0:
            return "skip"  # void* is unsafe
        return "plain"
    
    # Pointer to struct → plain (pass by reference)
    if ptr > 0 and base in defined_struct_names | opaque_struct_names:
        return "plain"
    
    # Struct by value (defined) → copy_or_move
    if ptr == 0 and base in defined_struct_names:
        return "copy_or_move"
    
    # Struct by value (opaque) → skip (unsafe)
    if ptr == 0 and base in opaque_struct_names:
        return "skip"
    
    # Unknown → skip
    return "skip"


# ─── Phase 2: Scalar typedef parsing and .das file generation ────────────────
def parse_scalar_typedefs(text: str) -> list:
    """
    Parse scalar typedefs from C header: typedef <primitive> <name>;
    Returns: [(typedef_name, das_type)] for all discovered scalar typedefs
    """
    results = []
    # Match: typedef <primitive_type> <name>;
    pat = re.compile(
        r"typedef\s+((?:unsigned|signed|const)?\s*(?:void|char|short|int|long|float|double|int\d+_t|uint\d+_t|size_t|ptrdiff_t))\s+(\w+)\s*;",
        re.MULTILINE
    )
    
    for m in pat.finditer(text):
        c_type = m.group(1).strip()
        name = m.group(2)
        
        # Skip if already in ALL_KNOWN_TYPES (it's a struct, not a scalar)
        if name in ALL_KNOWN_TYPES:
            continue
            
        # Map C type to DasLang
        if c_type in C_TO_DAS:
            das_type = C_TO_DAS[c_type]
            results.append((name, das_type))
        # Handle compound types like "unsigned int"
        elif "unsigned int" in c_type:
            results.append((name, "uint"))
        elif "unsigned short" in c_type:
            results.append((name, "uint16"))
        elif "unsigned long" in c_type:
            results.append((name, "uint64"))
        elif "unsigned char" in c_type:
            results.append((name, "uint8"))
    
    return results


def detect_opaque_structs(text: str) -> set:
    """
    Detect struct types that are forward-declared (opaque) vs full-defined.
    Returns: set of opaque struct names (typedef only, no body visible)
    """
    opaque = set()
    
    # Find all typedef'd structs (named and anonymous)
    # Pattern: typedef struct [name] { ... } typename; or typedef struct typename typename;
    
    # Forward-declare pattern: typedef struct Name Name;  (no body)
    forward_pat = re.compile(
        r"typedef\s+struct\s+(\w+)\s+\1\s*;",
        re.MULTILINE
    )
    for m in forward_pat.finditer(text):
        opaque.add(m.group(1))
    
    # Also catch pattern: typedef struct Name Name; without self-reference
    forward_pat2 = re.compile(
        r"typedef\s+struct\s+(\w+)\s*;\s*typedef\s+struct\s+\1\s+(\w+)\s*;",
        re.MULTILINE
    )
    for m in forward_pat2.finditer(text):
        opaque.add(m.group(2))
    
    return opaque


def parse_struct_fields(text: str) -> dict:
    """
    Parse struct field definitions from C header.
    Returns: {struct_name: [(field_type, field_name)]}
    
    Skips:
    - Function pointers: (*...)
    - Nested structs: contains unmatched {
    - Internal fields: start with __ or end with _
    - Arrays: [...]
    - Pointer fields: only bind scalar and struct-reference fields
    """
    results = {}
    
    # Match: typedef struct [name] { ... } typename; or struct typename { ... };
    struct_pat = re.compile(
        r"(?:typedef\s+)?struct\s+(?:\w+\s*)?\{([^}]*)\}\s*(\w+)?\s*;",
        re.MULTILINE | re.DOTALL
    )
    
    for m in struct_pat.finditer(text):
        body = m.group(1)
        struct_name = m.group(2)
        
        if not struct_name:
            continue
        
        # Skip if it's a forward declaration (empty body)
        if not body.strip():
            continue
        
        fields = []
        
        # Parse each line in the struct body
        for line in body.split(";"):
            line = line.strip()
            if not line or line.startswith("//"):
                continue
            
            # Skip function pointers
            if "(*" in line or "(*)" in line:
                continue
            
            # Skip nested structs (contains unmatched {)
            if "{" in line:
                continue
            
            # Skip internal/private fields
            if "__" in line or re.search(r"\b_\s*[,;=\[]", line):
                continue
            
            # Skip array fields for now
            if "[" in line:
                continue
            
            # Extract type and field name
            # Pattern: <type> [*] <name> [= init]
            # Remove comments, whitespace
            line = re.sub(r"/\*.*?\*/", "", line)  # Remove inline comments
            
            # Split into tokens
            tokens = line.split()
            if len(tokens) < 2:
                continue
            
            # Field name is the last token (without trailing *)
            field_name = tokens[-1].rstrip("*,=[]")
            if not field_name or field_name[0].isdigit() or not field_name.replace("_", "").isalnum():
                continue
            
            # Check if there's a pointer in the field (e.g., "Type *field")
            full_decl = " ".join(tokens[:-1]) + " " + tokens[-1]
            if "*" in full_decl and field_name != "*":
                # This is a pointer field; skip it
                continue
            
            # Reconstruct type (all tokens except last)
            field_type = " ".join(tokens[:-1])
            if not field_type:
                continue
            
            fields.append((field_type, field_name))
        
        if fields:
            results[struct_name] = fields
    
    return results


# ─── Phase 3: Struct field binding code generation ─────────────────────────────
def gen_struct_fields_in_annotation(struct_name: str, fields: list) -> list:
    """
    Generate addField lines for struct annotation constructor.
    Applies reserved keyword renaming.
    
    Returns: list of C++ code lines
    """
    lines = []
    
    for field_type, field_name in fields:
        # Check if field name is a reserved keyword that needs renaming
        das_name = DAS_RESERVED_FIELD_RENAMES.get(field_name, field_name)
        
        # Generate addField call
        lines.append(
            f"        addField<DAS_BIND_MANAGED_FIELD({field_name})>"
            f"(\"{das_name}\", \"{field_name}\");"
        )
    
    return lines


# ─── Phase 4: Scalar typedefs and enum constants for .das file ────────────────
def gen_raylib_das_additions(scalar_typedefs: list, enums: list) -> str:
    """
    Generate scalar typedef aliases and enum constants for raylib.das
    """
    lines = [
        "// BEGIN GENERATED TYPEDEFS",
        "",
    ]
    
    # Add scalar typedefs
    for typedef_name, das_type in scalar_typedefs:
        lines.append(f"typedef {typedef_name} = {das_type}")
    
    lines.extend([
        "",
        "// END GENERATED TYPEDEFS",
        "",
        "// BEGIN GENERATED ENUM CONSTANTS",
        "",
    ])
    
    # Add enum constants
    for enum_name, members in enums:
        lines.append(f"// {enum_name}")
        for i, (member_name, value_str) in enumerate(members):
            if value_str:
                # Use explicit value from C header
                lines.append(f"let {member_name} : int = {value_str}")
            else:
                # Use sequential index
                lines.append(f"let {member_name} : int = {i}")
        lines.append("")
    
    lines.append("// END GENERATED ENUM CONSTANTS")
    
    return "\n".join(lines)


def update_raylib_das(das_file_path: str, new_content: str) -> None:
    """
    Update raylib.das with new scalar typedefs and enum constants.
    Preserves hand-written sections outside the markers.
    Only updates if file exists (requires manual setup).
    """
    if not os.path.exists(das_file_path):
        return
    
    # Read existing file
    try:
        with open(das_file_path, "r", encoding="utf-8") as f:
            existing = f.read()
    except:
        return
    
    # If file has markers, replace content between them
    if "// BEGIN GENERATED TYPEDEFS" in existing and "// END GENERATED ENUM CONSTANTS" in existing:
        # Find marker positions
        start_idx = existing.find("// BEGIN GENERATED TYPEDEFS")
        end_idx = existing.find("// END GENERATED ENUM CONSTANTS") + len("// END GENERATED ENUM CONSTANTS")
        
        # Reconstruct with new content
        content = existing[:start_idx] + new_content + existing[end_idx:]
    else:
        # No markers found; append to end of file
        if existing and not existing.endswith("\n"):
            content = existing + "\n\n" + new_content + "\n"
        else:
            content = (existing or "") + new_content + "\n"
    
    # Write updated content
    try:
        with open(das_file_path, "w", encoding="utf-8", newline="\n") as f:
            f.write(content)
    except Exception as e:
        print(f"  Warning: Could not update {das_file_path}: {e}")

def gen_enums_inc(enums: list) -> str:
    lines = [
        "// GENERATED — do not edit manually.",
        "// Regenerate with: python3 tools/gen_raylib_bindings.py",
        "",
        "#pragma once",
        "",
    ]

    for enum_name, members in enums:
        # DAS_BIND_ENUM_CAST tells daslang to use this C enum as a typed enum
        lines.append(f"DAS_BIND_ENUM_CAST({enum_name});")
    lines.append("")

    for enum_name, members in enums:
        member_names = [n for n, _ in members]
        members_list = ", ".join(member_names)
        lines.append(
            f"DAS_BASE_BIND_ENUM({enum_name}, {enum_name}, {members_list});"
        )
    lines.append("")

    return "\n".join(lines)


def gen_annotations_inc(extra_structs: list, opaque_struct_names: set = None, struct_fields_map: dict = None) -> str:
    """
    Generate ManagedStructureAnnotation definitions for struct types
    not already hand-written (Camera3D, Camera2D, etc.)
    
    NEW: Include field bindings and split opaque vs. defined types
    Excludes any types in HANDWRITTEN_TYPES (already declared in module_raylib.cpp)
    """
    if opaque_struct_names is None:
        opaque_struct_names = set()
    if struct_fields_map is None:
        struct_fields_map = {}
    
    # Filter out hand-written types only
    auto_structs = [s for s in extra_structs if s not in HANDWRITTEN_TYPES]
    
    lines = [
        "// GENERATED — do not edit manually.",
        "// Regenerate with: python3 tools/gen_raylib_bindings.py",
        "",
        "#pragma once",
        "",
    ]
    
    # --- Opaque types (DummyTypeAnnotation) ---
    opaque_types = [s for s in auto_structs if s in opaque_struct_names]
    if opaque_types:
        lines.append("// --- Opaque types (DummyTypeAnnotation) ---")
        lines.append("")
        for struct_name in opaque_types:
            ann_name = f"Raylib{struct_name}Annotation"
            lines += [
                f"MAKE_TYPE_FACTORY({struct_name}, {struct_name})",
                f"struct {ann_name} : das::DummyTypeAnnotation {{",
                f"    {ann_name}()",
                f"        : DummyTypeAnnotation(\"{struct_name}\", \"{struct_name}\", sizeof(void*), alignof(void*)) {{",
                f"    }}",
                f"}};",
                "",
            ]
        lines.append("")
    
    # --- Defined structs (ManagedStructureAnnotation) ---
    defined_types = [s for s in auto_structs if s not in opaque_struct_names]
    if defined_types:
        lines.append("// --- Defined structs (ManagedStructureAnnotation with field bindings) ---")
        lines.append("")
        for struct_name in defined_types:
            ann_name = f"Raylib{struct_name}Annotation"
            lines += [
                f"MAKE_TYPE_FACTORY({struct_name}, {struct_name})",
                f"struct {ann_name} : das::ManagedStructureAnnotation<{struct_name}, false> {{",
                f"    {ann_name}(das::ModuleLibrary &lib)",
                f"        : ManagedStructureAnnotation(\"{struct_name}\", lib) {{",
            ]

            # Add field bindings if available
            if struct_name in struct_fields_map:
                field_lines = gen_struct_fields_in_annotation(struct_name, struct_fields_map[struct_name])
                lines.extend(field_lines)

            lines += [
                f"    }}",
                f"}};",
                "",
            ]
        lines.append("")
    
    return "\n".join(lines)



def gen_register_inc(enums: list, functions: list, extra_structs: list, opaque_struct_names: set = None) -> str:
    if opaque_struct_names is None:
        opaque_struct_names = set()
    
    defined_struct_names = set(extra_structs) - opaque_struct_names
    
    lines = [
        "// GENERATED — do not edit manually.",
        "// Regenerate with: python3 tools/gen_raylib_bindings.py",
        "",
    ]

    # Enum registrations
    lines.append("// --- Enum registrations ---")
    lines.append("")
    for enum_name, _ in enums:
        lines.append(f"addEnumeration(new Enumeration{enum_name}());")
    lines.append("")

    # Extra struct annotation registrations (only auto-generated, not hand-written)
    auto_structs = [
        s for s in extra_structs
        if s not in HANDWRITTEN_TYPES and s not in REGISTER_EXCLUDED_STRUCT_TYPES
    ]
    if auto_structs:
        lines.append("// --- Extra struct annotation registrations ---")
        lines.append("")
        for struct_name in auto_structs:
            ann_name = f"Raylib{struct_name}Annotation"
            # Opaque types don't need lib parameter
            if struct_name in opaque_struct_names:
                lines.append(f"addAnnotation(new {ann_name}());")
            else:
                lines.append(f"addAnnotation(new {ann_name}(lib));")
        lines.append("")

    # Function registrations
    lines.append("// --- Function registrations ---")
    lines.append("")

    skipped = []
    bound = []

    for fn in functions:
        name = fn["name"]
        ret_c = fn["ret"]
        params = fn["params"]

        # Classify return type
        ret_classification = classify_return(ret_c, defined_struct_names, opaque_struct_names)
        
        # Check if return type is convertible to DasLang
        ret_das = c_type_to_das(ret_c, is_return=True)
        if ret_das is None or ret_classification == "skip":
            skipped.append(f"// SKIP {name}: unsupported return type '{ret_c}'")
            continue

        # Convert all param types
        ok = True
        for ptype, pname in params:
            pinfo = parse_type(ptype)
            pbase = pinfo["base"]
            pptr  = pinfo["ptr_depth"]

            # Skip struct-by-value params (daScript interop cast<T> is not available for these)
            if pptr == 0 and pbase in (defined_struct_names | opaque_struct_names | HANDWRITTEN_TYPES):
                skipped.append(f"// SKIP {name}: struct-by-value param '{ptype} {pname}' requires manual wrapper")
                ok = False
                break

            das_t = c_type_to_das(ptype)
            if das_t is None:
                skipped.append(f"// SKIP {name}: unsupported param '{ptype} {pname}'")
                ok = False
                break
        if not ok:
            continue

        # Use correct registration based on return type classification
        if ret_classification == "copy_or_move":
            # Struct by value → needs special SimNode
            bound.append(
                f"das::addExtern<DAS_BIND_FUN({name}), das::SimNode_ExtFuncCallAndCopyOrMove>"
                f"(*this, lib, \"{name}\", {SIDE_EFFECTS}, \"{name}\");"
            )
        else:
            # Plain return (void, scalar, pointer, const char*)
            bound.append(
                f"das::addExtern<DAS_BIND_FUN({name})>"
                f"(*this, lib, \"{name}\", {SIDE_EFFECTS}, \"{name}\");"
            )

    lines += bound
    lines.append("")
    lines.append("// --- Skipped functions (need manual wrappers) ---")
    lines += skipped
    lines.append("")

    return "\n".join(lines)



# ─── Wrapper generation for const char* returns ──────────────────────────────
def gen_string_wrappers(functions: list) -> str:
    """
    For functions that return const char*, generate a thin C++ wrapper that
    returns a daslang-managed string copy. Also wraps functions taking
    non-const char* where daslang would pass a string.
    """
    lines = [
        "// GENERATED — do not edit manually.",
        "// Regenerate with: python3 tools/gen_raylib_bindings.py",
        "",
        "// Wrappers for functions returning const char* (daslang needs char* from heap)",
        "",
    ]

    for fn in functions:
        name = fn["name"]
        ret_c = fn["ret"]
        params = fn["params"]

        info = parse_type(ret_c)
        if not (info["base"] == "char" and info["ptr_depth"] == 1 and info["is_const"]):
            continue
        if name in SKIP_FUNCS:
            continue

        # Build param list
        param_decls = []
        param_calls = []
        ok = True
        for ptype, pname in params:
            pinfo = parse_type(ptype)
            if pinfo["ptr_depth"] > 1:
                ok = False
                break
            if pinfo["base"] == "char" and pinfo["ptr_depth"] == 1:
                param_decls.append(f"const char *{pname}")
            elif pinfo["base"] in ALL_KNOWN_TYPES and pinfo["ptr_depth"] == 1:
                param_decls.append(f"{pinfo['base']} &{pname}")
            elif pinfo["base"] in ALL_KNOWN_TYPES:
                param_decls.append(f"{pinfo['base']} {pname}")
            elif pinfo["base"] in C_TO_DAS:
                ptr_str = " *" if pinfo["ptr_depth"] else ""
                param_decls.append(f"{pinfo['base']}{ptr_str} {pname}")
            else:
                ok = False
                break
            param_calls.append(pname)
        if not ok:
            continue

        wrapper_name = f"raylib_wrap_{name}"
        # "void" means no params at all in C
        decl_str = ", ".join(param_decls) if param_decls else ""
        call_str = ", ".join(param_calls)
        
        # Build parameter list correctly: if there are params, add comma before ctx; otherwise just ctx
        if decl_str:
            param_list = f"{decl_str}, das::Context *ctx"
        else:
            param_list = "das::Context *ctx"

        lines += [
            f"// Wrapper: {name} -> returns das-managed string",
            f"static char *{wrapper_name}({param_list}) {{",
            f"    const char *s = {name}({call_str});",
            f"    return s ? ctx->stringHeap->impl_allocateString(ctx, s, (uint32_t)strlen(s)) : nullptr;",
            f"}}",
            "",
        ]

    return "\n".join(lines)


def gen_string_wrapper_register(functions: list) -> str:
    """Registration lines for the string wrappers."""
    lines = []
    for fn in functions:
        name = fn["name"]
        ret_c = fn["ret"]
        if name in SKIP_FUNCS:
            continue
        info = parse_type(ret_c)
        if info["base"] == "char" and info["ptr_depth"] == 1 and info["is_const"]:
            wrapper_name = f"raylib_wrap_{name}"
            lines.append(
                f"das::addExtern<DAS_BIND_FUN({wrapper_name})>"
                f"(*this, lib, \"{name}\", {SIDE_EFFECTS}, \"{wrapper_name}\");"
            )
    return "\n".join(lines)


# ─── Main ─────────────────────────────────────────────────────────────────────
def main():
    if len(sys.argv) < 3:
        print(f"Usage: {sys.argv[0]} <raylib.h> <out_dir>")
        sys.exit(1)

    header_path = sys.argv[1]
    out_dir = sys.argv[2]
    os.makedirs(out_dir, exist_ok=True)

    with open(header_path, "r", encoding="utf-8", errors="ignore") as f:
        raw = f.read()

    text = strip_comments(raw)

    # --- Phase 2: Parse scalar typedefs and enums ---
    scalar_typedefs = parse_scalar_typedefs(text)
    enums = parse_enums(text)
    
    # --- Phase 3: Parse struct fields and detect opaque types ---
    struct_fields_map = parse_struct_fields(text)
    opaque_struct_names = detect_opaque_structs(text)
    
    # --- Phase 1: Parse functions for later classification ---
    functions = parse_functions(text)

    extra_structs = sorted(EXTRA_STRUCT_TYPES)
    
    # Separate functions that return const char* (need wrappers)
    # from those that don't (direct bind)
    const_char_return_names = set()
    for fn in functions:
        info = parse_type(fn["ret"])
        if info["base"] == "char" and info["ptr_depth"] == 1 and info["is_const"]:
            const_char_return_names.add(fn["name"])

    # Remove const-char-return fns from the direct-bind list
    direct_fns = [f for f in functions if f["name"] not in const_char_return_names]
    str_fns    = [f for f in functions if f["name"] in const_char_return_names]

    # --- Generate output files ---
    enums_inc    = gen_enums_inc(enums)
    annot_inc    = gen_annotations_inc(extra_structs, opaque_struct_names, struct_fields_map)
    wrappers_cpp = gen_string_wrappers(str_fns)
    register_inc = gen_register_inc(enums, direct_fns, extra_structs, opaque_struct_names)

    # Append string wrapper registrations to register.inc
    str_reg = gen_string_wrapper_register(str_fns)
    if str_reg:
        register_inc = register_inc.rstrip() + "\n\n// --- String-returning wrappers ---\n" + str_reg + "\n"

    # --- Phase 2: Generate and update raylib.das with scalar typedefs & enum constants ---
    das_additions = gen_raylib_das_additions(scalar_typedefs, enums)
    
    # Construct path to raylib.das (typically in <project>/rl_das/src/scripts/raylib.das)
    # Based on output dir structure: <generated> → up 1 level → scripts/raylib.das
    possible_das_path = os.path.join(
        os.path.dirname(out_dir),  # Go up from generated dir
        "scripts",
        "raylib.das"
    )
    
    # TODO Prevent writing to raylib.das and raylib_helper.das
    # Only update if the file exists (don't create if missing; require manual setup)
    # if os.path.exists(possible_das_path):
    #     update_raylib_das(possible_das_path, das_additions)
    #     print(f"  Updated {possible_das_path}")

    def write(name, content):
        path = os.path.join(out_dir, name)
        with open(path, "w", encoding="utf-8", newline="\n") as f:
            f.write(content)
        print(f"  Wrote {path}")

    write("module_raylib_enums.inc",       enums_inc)
    write("module_raylib_annotations.inc", annot_inc)
    write("module_raylib_string_wrappers.inc", wrappers_cpp)
    write("module_raylib_register.inc",    register_inc)

    bound_count = register_inc.count("addExtern")
    skipped_count = register_inc.count("// SKIP")
    copy_or_move_count = register_inc.count("SimNode_ExtFuncCallAndCopyOrMove")
    opaque_count = len(opaque_struct_names)
    defined_struct_count = len(extra_structs) - opaque_count
    
    print(f"\n=== Generation Summary ===")
    print(f"Parsed:")
    print(f"  {len(enums)} enums")
    print(f"  {len(functions)} RLAPI functions")
    print(f"  {len(scalar_typedefs)} scalar typedefs")
    print(f"  {len(struct_fields_map)} structs with fields")
    print(f"  {opaque_count} opaque types")
    print(f"  {defined_struct_count} defined struct types")
    print(f"\nBindings:")
    print(f"  Registered:     {bound_count}")
    print(f"  Copy-or-move:   {copy_or_move_count}")
    print(f"  Skipped:        {skipped_count}")
    print(f"\nGenerated files:")
    print(f"  module_raylib_annotations.inc (with field bindings)")
    print(f"  module_raylib_register.inc (with return type classification)")
    print(f"  module_raylib_enums.inc")
    print(f"  module_raylib_string_wrappers.inc")
    
    if os.path.exists(possible_das_path):
        print(f"  {possible_das_path} (updated with scalar typedefs & enum constants)")

    return 0



if __name__ == "__main__":
    sys.exit(main())
