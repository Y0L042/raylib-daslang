#include "module_raylib.h"
#include <daScript/daScript.h>
#include <raylib.h>
#include <raymath.h>

//#include "scripts/raylib.das.inc"
//#include "scripts/raylib_helpers.das.inc"

// ─── Generated enum casts (must be outside namespace) ────────────────────────
#include "generated/module_raylib_enums.inc"

// ─── Generated extra struct type factories (must be outside namespace) ────────
#include "generated/module_raylib_annotations.inc"

// ─── Hand-written annotations for manually-registered raylib types ───────────
MAKE_TYPE_FACTORY(Vector2, Vector2);
struct RaylibVector2Annotation : das::ManagedStructureAnnotation<Vector2>
{
    RaylibVector2Annotation(das::ModuleLibrary &lib) : ManagedStructureAnnotation("Vector2", lib)
    {
        this->cppName = "Vector2";
        addField<DAS_BIND_MANAGED_FIELD(x)>("x", "x");
        addField<DAS_BIND_MANAGED_FIELD(y)>("y", "y");
    }
};

MAKE_TYPE_FACTORY(Vector3, Vector3);
struct RaylibVector3Annotation : das::ManagedStructureAnnotation<Vector3>
{
    RaylibVector3Annotation(das::ModuleLibrary &lib) : ManagedStructureAnnotation("Vector3", lib)
    {
        this->cppName = "Vector3";
        addField<DAS_BIND_MANAGED_FIELD(x)>("x", "x");
        addField<DAS_BIND_MANAGED_FIELD(y)>("y", "y");
        addField<DAS_BIND_MANAGED_FIELD(z)>("z", "z");
    }
};

MAKE_TYPE_FACTORY(Vector4, Vector4);
struct RaylibVector4Annotation : das::ManagedStructureAnnotation<Vector4>
{
    RaylibVector4Annotation(das::ModuleLibrary &lib) : ManagedStructureAnnotation("Vector4", lib)
    {
        this->cppName = "Vector4";
        addField<DAS_BIND_MANAGED_FIELD(x)>("x", "x");
        addField<DAS_BIND_MANAGED_FIELD(y)>("y", "y");
        addField<DAS_BIND_MANAGED_FIELD(z)>("z", "z");
        addField<DAS_BIND_MANAGED_FIELD(w)>("w", "w");
    }
};

// NOTE: Matrix is already defined in daScript, so we don't redefine it

MAKE_TYPE_FACTORY(Color, Color);
struct RaylibColorAnnotation : das::ManagedStructureAnnotation<Color>
{
    RaylibColorAnnotation(das::ModuleLibrary &lib) : ManagedStructureAnnotation("Color", lib)
    {
        this->cppName = "Color";
        addField<DAS_BIND_MANAGED_FIELD(r)>("r", "r");
        addField<DAS_BIND_MANAGED_FIELD(g)>("g", "g");
        addField<DAS_BIND_MANAGED_FIELD(b)>("b", "b");
        addField<DAS_BIND_MANAGED_FIELD(a)>("a", "a");
    }
};

MAKE_TYPE_FACTORY(Rectangle, Rectangle);
struct RaylibRectangleAnnotation : das::ManagedStructureAnnotation<Rectangle>
{
    RaylibRectangleAnnotation(das::ModuleLibrary &lib) : ManagedStructureAnnotation("Rectangle", lib)
    {
        this->cppName = "Rectangle";
        addField<DAS_BIND_MANAGED_FIELD(x)>("x", "x");
        addField<DAS_BIND_MANAGED_FIELD(y)>("y", "y");
        addField<DAS_BIND_MANAGED_FIELD(width)>("width", "width");
        addField<DAS_BIND_MANAGED_FIELD(height)>("height", "height");
    }
};

MAKE_TYPE_FACTORY(Image, Image);
struct RaylibImageAnnotation : das::ManagedStructureAnnotation<Image>
{
    RaylibImageAnnotation(das::ModuleLibrary &lib) : ManagedStructureAnnotation("Image", lib)
    {
        this->cppName = "Image";
        addField<DAS_BIND_MANAGED_FIELD(width)>("width", "width");
        addField<DAS_BIND_MANAGED_FIELD(height)>("height", "height");
        addField<DAS_BIND_MANAGED_FIELD(mipmaps)>("mipmaps", "mipmaps");
        addField<DAS_BIND_MANAGED_FIELD(format)>("format", "format");
    }
};

MAKE_TYPE_FACTORY(Texture, Texture);
struct RaylibTextureAnnotation : das::ManagedStructureAnnotation<Texture>
{
    RaylibTextureAnnotation(das::ModuleLibrary &lib) : ManagedStructureAnnotation("Texture", lib)
    {
        this->cppName = "Texture";
        addField<DAS_BIND_MANAGED_FIELD(id)>("id", "id");
        addField<DAS_BIND_MANAGED_FIELD(width)>("width", "width");
        addField<DAS_BIND_MANAGED_FIELD(height)>("height", "height");
        addField<DAS_BIND_MANAGED_FIELD(mipmaps)>("mipmaps", "mipmaps");
        addField<DAS_BIND_MANAGED_FIELD(format)>("format", "format");
    }
};

MAKE_TYPE_FACTORY(RenderTexture, RenderTexture);
struct RaylibRenderTextureAnnotation : das::ManagedStructureAnnotation<RenderTexture>
{
    RaylibRenderTextureAnnotation(das::ModuleLibrary &lib) : ManagedStructureAnnotation("RenderTexture", lib)
    {
        this->cppName = "RenderTexture";
        addField<DAS_BIND_MANAGED_FIELD(id)>("id", "id");
    }
};

MAKE_TYPE_FACTORY(NPatchInfo, NPatchInfo);
struct RaylibNPatchInfoAnnotation : das::ManagedStructureAnnotation<NPatchInfo>
{
    RaylibNPatchInfoAnnotation(das::ModuleLibrary &lib) : ManagedStructureAnnotation("NPatchInfo", lib)
    {
        this->cppName = "NPatchInfo";
        addField<DAS_BIND_MANAGED_FIELD(left)>("left", "left");
        addField<DAS_BIND_MANAGED_FIELD(top)>("top", "top");
        addField<DAS_BIND_MANAGED_FIELD(right)>("right", "right");
        addField<DAS_BIND_MANAGED_FIELD(bottom)>("bottom", "bottom");
        addField<DAS_BIND_MANAGED_FIELD(layout)>("layout", "layout");
    }
};

MAKE_TYPE_FACTORY(GlyphInfo, GlyphInfo);
struct RaylibGlyphInfoAnnotation : das::ManagedStructureAnnotation<GlyphInfo>
{
    RaylibGlyphInfoAnnotation(das::ModuleLibrary &lib) : ManagedStructureAnnotation("GlyphInfo", lib)
    {
        this->cppName = "GlyphInfo";
        addField<DAS_BIND_MANAGED_FIELD(value)>("value", "value");
        addField<DAS_BIND_MANAGED_FIELD(offsetX)>("offsetX", "offsetX");
        addField<DAS_BIND_MANAGED_FIELD(offsetY)>("offsetY", "offsetY");
        addField<DAS_BIND_MANAGED_FIELD(advanceX)>("advanceX", "advanceX");
    }
};

MAKE_TYPE_FACTORY(Font, Font);
struct RaylibFontAnnotation : das::ManagedStructureAnnotation<Font>
{
    RaylibFontAnnotation(das::ModuleLibrary &lib) : ManagedStructureAnnotation("Font", lib)
    {
        this->cppName = "Font";
        addField<DAS_BIND_MANAGED_FIELD(baseSize)>("baseSize", "baseSize");
        addField<DAS_BIND_MANAGED_FIELD(glyphCount)>("glyphCount", "glyphCount");
        addField<DAS_BIND_MANAGED_FIELD(glyphPadding)>("glyphPadding", "glyphPadding");
    }
};

MAKE_TYPE_FACTORY(Mesh, Mesh);
struct RaylibMeshAnnotation : das::ManagedStructureAnnotation<Mesh>
{
    RaylibMeshAnnotation(das::ModuleLibrary &lib) : ManagedStructureAnnotation("Mesh", lib)
    {
        this->cppName = "Mesh";
        addField<DAS_BIND_MANAGED_FIELD(vertexCount)>("vertexCount", "vertexCount");
        addField<DAS_BIND_MANAGED_FIELD(triangleCount)>("triangleCount", "triangleCount");
    }
};

MAKE_TYPE_FACTORY(Shader, Shader);
struct RaylibShaderAnnotation : das::ManagedStructureAnnotation<Shader>
{
    RaylibShaderAnnotation(das::ModuleLibrary &lib) : ManagedStructureAnnotation("Shader", lib)
    {
        this->cppName = "Shader";
        addField<DAS_BIND_MANAGED_FIELD(id)>("id", "id");
    }
};

MAKE_TYPE_FACTORY(MaterialMap, MaterialMap);
struct RaylibMaterialMapAnnotation : das::ManagedStructureAnnotation<MaterialMap>
{
    RaylibMaterialMapAnnotation(das::ModuleLibrary &lib) : ManagedStructureAnnotation("MaterialMap", lib)
    {
        this->cppName = "MaterialMap";
    }
};

MAKE_TYPE_FACTORY(Material, Material);
struct RaylibMaterialAnnotation : das::ManagedStructureAnnotation<Material>
{
    RaylibMaterialAnnotation(das::ModuleLibrary &lib) : ManagedStructureAnnotation("Material", lib)
    {
        this->cppName = "Material";
    }
};

MAKE_TYPE_FACTORY(Transform, Transform);
struct RaylibTransformAnnotation : das::ManagedStructureAnnotation<Transform>
{
    RaylibTransformAnnotation(das::ModuleLibrary &lib) : ManagedStructureAnnotation("Transform", lib)
    {
        this->cppName = "Transform";
    }
};

MAKE_TYPE_FACTORY(BoneInfo, BoneInfo);
struct RaylibBoneInfoAnnotation : das::ManagedStructureAnnotation<BoneInfo>
{
    RaylibBoneInfoAnnotation(das::ModuleLibrary &lib) : ManagedStructureAnnotation("BoneInfo", lib)
    {
        this->cppName = "BoneInfo";
    }
};

MAKE_TYPE_FACTORY(Model, Model);
struct RaylibModelAnnotation : das::ManagedStructureAnnotation<Model>
{
    RaylibModelAnnotation(das::ModuleLibrary &lib) : ManagedStructureAnnotation("Model", lib)
    {
        this->cppName = "Model";
    }
};

MAKE_TYPE_FACTORY(ModelAnimation, ModelAnimation);
struct RaylibModelAnimationAnnotation : das::ManagedStructureAnnotation<ModelAnimation>
{
    RaylibModelAnimationAnnotation(das::ModuleLibrary &lib) : ManagedStructureAnnotation("ModelAnimation", lib)
    {
        this->cppName = "ModelAnimation";
    }
};

MAKE_TYPE_FACTORY(Ray, Ray);
struct RaylibRayAnnotation : das::ManagedStructureAnnotation<Ray>
{
    RaylibRayAnnotation(das::ModuleLibrary &lib) : ManagedStructureAnnotation("Ray", lib)
    {
        this->cppName = "Ray";
    }
};

MAKE_TYPE_FACTORY(RayCollision, RayCollision);
struct RaylibRayCollisionAnnotation : das::ManagedStructureAnnotation<RayCollision>
{
    RaylibRayCollisionAnnotation(das::ModuleLibrary &lib) : ManagedStructureAnnotation("RayCollision", lib)
    {
        this->cppName = "RayCollision";
    }
};

MAKE_TYPE_FACTORY(BoundingBox, BoundingBox);
struct RaylibBoundingBoxAnnotation : das::ManagedStructureAnnotation<BoundingBox>
{
    RaylibBoundingBoxAnnotation(das::ModuleLibrary &lib) : ManagedStructureAnnotation("BoundingBox", lib)
    {
        this->cppName = "BoundingBox";
    }
};

MAKE_TYPE_FACTORY(Wave, Wave);
struct RaylibWaveAnnotation : das::ManagedStructureAnnotation<Wave>
{
    RaylibWaveAnnotation(das::ModuleLibrary &lib) : ManagedStructureAnnotation("Wave", lib)
    {
        this->cppName = "Wave";
    }
};

MAKE_TYPE_FACTORY(AudioStream, AudioStream);
struct RaylibAudioStreamAnnotation : das::ManagedStructureAnnotation<AudioStream>
{
    RaylibAudioStreamAnnotation(das::ModuleLibrary &lib) : ManagedStructureAnnotation("AudioStream", lib)
    {
        this->cppName = "AudioStream";
    }
};

MAKE_TYPE_FACTORY(Sound, Sound);
struct RaylibSoundAnnotation : das::ManagedStructureAnnotation<Sound>
{
    RaylibSoundAnnotation(das::ModuleLibrary &lib) : ManagedStructureAnnotation("Sound", lib)
    {
        this->cppName = "Sound";
    }
};

MAKE_TYPE_FACTORY(Music, Music);
struct RaylibMusicAnnotation : das::ManagedStructureAnnotation<Music>
{
    RaylibMusicAnnotation(das::ModuleLibrary &lib) : ManagedStructureAnnotation("Music", lib)
    {
        this->cppName = "Music";
    }
};

// ─── Helper: Vector2 creation ─────────────────────────────────────────────────
static Vector2 raylib_make_vector2(float x, float y)
{
    return {x, y};
}

// ─── Helper: Vector3 creation ─────────────────────────────────────────────────
static Vector3 raylib_make_vector3(float x, float y, float z)
{
    return {x, y, z};
}

// ─── Helper: Color creation ───────────────────────────────────────────────────
static Color raylib_make_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    return {r, g, b, a};
}

// ─── Helper: Rectangle creation ───────────────────────────────────────────────
static Rectangle raylib_make_rectangle(float x, float y, float width, float height)
{
    return {x, y, width, height};
}

// ─── Preset colors ────────────────────────────────────────────────────────────
static Color raylib_color_lightgray()
{
    return LIGHTGRAY;
}
static Color raylib_color_gray()
{
    return GRAY;
}
static Color raylib_color_darkgray()
{
    return DARKGRAY;
}
static Color raylib_color_yellow()
{
    return YELLOW;
}
static Color raylib_color_gold()
{
    return GOLD;
}
static Color raylib_color_orange()
{
    return ORANGE;
}
static Color raylib_color_pink()
{
    return PINK;
}
static Color raylib_color_red()
{
    return RED;
}
static Color raylib_color_maroon()
{
    return MAROON;
}
static Color raylib_color_green()
{
    return GREEN;
}
static Color raylib_color_lime()
{
    return LIME;
}
static Color raylib_color_darkgreen()
{
    return DARKGREEN;
}
static Color raylib_color_skyblue()
{
    return SKYBLUE;
}
static Color raylib_color_blue()
{
    return BLUE;
}
static Color raylib_color_darkblue()
{
    return DARKBLUE;
}
static Color raylib_color_purple()
{
    return PURPLE;
}
static Color raylib_color_violet()
{
    return VIOLET;
}
static Color raylib_color_darkpurple()
{
    return DARKPURPLE;
}
static Color raylib_color_beige()
{
    return BEIGE;
}
static Color raylib_color_brown()
{
    return BROWN;
}
static Color raylib_color_darkbrown()
{
    return DARKBROWN;
}
static Color raylib_color_white()
{
    return WHITE;
}
static Color raylib_color_black()
{
    return BLACK;
}
static Color raylib_color_blank()
{
    return BLANK;
}
static Color raylib_color_magenta()
{
    return MAGENTA;
}
static Color raylib_color_raywhite()
{
    return RAYWHITE;
}

// ─── Wrapper functions for APIs taking struct parameters ──────────────────────
static void raylib_clear_background(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    ClearBackground({r, g, b, a});
}

static Vector2 raylib_get_mouse_delta()
{
    return GetMouseDelta();
}

static Vector3 raylib_vector3_rotate_by_axis_angle(const Vector3 &v, const Vector3 &axis, float angle)
{
    return Vector3RotateByAxisAngle(v, axis, angle);
}

static float raylib_vector3_length(const Vector3 &v)
{
    return Vector3Length(v);
}

static Vector3 raylib_vector3_scale(const Vector3 &v, float scale)
{
    return Vector3Scale(v, scale);
}

static Vector3 raylib_vector3_add(const Vector3 &v1, const Vector3 &v2)
{
    return Vector3Add(v1, v2);
}

static Vector3 raylib_vector3_subtract(const Vector3 &v1, const Vector3 &v2)
{
    return Vector3Subtract(v1, v2);
}

static Vector3 raylib_vector3_cross_product(const Vector3 &v1, const Vector3 &v2)
{
    return Vector3CrossProduct(v1, v2);
}

static Vector3 raylib_vector3_normalize(const Vector3 &v)
{
    return Vector3Normalize(v);
}

static void raylib_begin_mode_3d(const Camera3D &camera)
{
    BeginMode3D(camera);
}

static void raylib_draw_grid(int slices, float spacing)
{
    DrawGrid(slices, spacing);
}

static void raylib_draw_cube_v(const Vector3 &position, const Vector3 &size, const Color &color)
{
    DrawCubeV(position, size, color);
}

static void raylib_draw_cube_wires_v(const Vector3 &position, const Vector3 &size, const Color &color)
{
    DrawCubeWiresV(position, size, color);
}

static void raylib_draw_sphere(const Vector3 &centerPos, float radius, const Color &color)
{
    DrawSphere(centerPos, radius, color);
}

static Color raylib_fade(const Color &color, float alpha)
{
    return Fade(color, alpha);
}

static void raylib_draw_rectangle_lines(int posX, int posY, int width, int height, const Color &color)
{
    DrawRectangleLines(posX, posY, width, height, color);
}

static void raylib_draw_rectangle(int posX, int posY, int width, int height, const Color &color)
{
    DrawRectangle(posX, posY, width, height, color);
}

static void raylib_draw_text(const char *text, int posX, int posY, int fontSize, const Color &color)
{
    DrawText(text, posX, posY, fontSize, color);
}

// ─── String-returning wrappers ────────────────────────────────────────────────
#include "generated/module_raylib_string_wrappers.inc"

// ─── Module ───────────────────────────────────────────────────────────────────
class Module_raylib : public das::Module
{
  public:
    Module_raylib() : das::Module("raylib")
    {
        das::ModuleLibrary lib(this);
        addBuiltinDependency(lib, require("math"));

        // ── Hand-registered struct annotations ──────────────────────────────
        addAnnotation(das::make_smart<RaylibVector2Annotation>(lib));
        addAnnotation(das::make_smart<RaylibVector3Annotation>(lib));
        addAnnotation(das::make_smart<RaylibVector4Annotation>(lib));
        // NOTE: Matrix is already defined in daScript, no need to re-register
        addAnnotation(das::make_smart<RaylibColorAnnotation>(lib));
        addAnnotation(das::make_smart<RaylibRectangleAnnotation>(lib));
        addAnnotation(das::make_smart<RaylibImageAnnotation>(lib));
        addAnnotation(das::make_smart<RaylibTextureAnnotation>(lib));
        addAnnotation(das::make_smart<RaylibRenderTextureAnnotation>(lib));
        addAnnotation(das::make_smart<RaylibNPatchInfoAnnotation>(lib));
        addAnnotation(das::make_smart<RaylibGlyphInfoAnnotation>(lib));
        addAnnotation(das::make_smart<RaylibFontAnnotation>(lib));
        addAnnotation(das::make_smart<RaylibMeshAnnotation>(lib));
        addAnnotation(das::make_smart<RaylibShaderAnnotation>(lib));
        addAnnotation(das::make_smart<RaylibMaterialMapAnnotation>(lib));
        addAnnotation(das::make_smart<RaylibMaterialAnnotation>(lib));
        addAnnotation(das::make_smart<RaylibTransformAnnotation>(lib));
        addAnnotation(das::make_smart<RaylibBoneInfoAnnotation>(lib));
        addAnnotation(das::make_smart<RaylibModelAnnotation>(lib));
        addAnnotation(das::make_smart<RaylibModelAnimationAnnotation>(lib));
        addAnnotation(das::make_smart<RaylibRayAnnotation>(lib));
        addAnnotation(das::make_smart<RaylibRayCollisionAnnotation>(lib));
        addAnnotation(das::make_smart<RaylibBoundingBoxAnnotation>(lib));
        addAnnotation(das::make_smart<RaylibWaveAnnotation>(lib));
        addAnnotation(das::make_smart<RaylibAudioStreamAnnotation>(lib));
        addAnnotation(das::make_smart<RaylibSoundAnnotation>(lib));
        addAnnotation(das::make_smart<RaylibMusicAnnotation>(lib));
        addAnnotation(das::make_smart<RaylibCamera2DAnnotation>(lib));
        addAnnotation(das::make_smart<RaylibCamera3DAnnotation>(lib));

        // ── Construction helpers (struct returns need CopyOrMove) ─────────────
        das::addExtern<DAS_BIND_FUN(raylib_make_vector2), das::SimNode_ExtFuncCallAndCopyOrMove>(
            *this, lib, "make_vector2", das::SideEffects::none, "raylib_make_vector2");
        das::addExtern<DAS_BIND_FUN(raylib_make_vector3), das::SimNode_ExtFuncCallAndCopyOrMove>(
            *this, lib, "make_vector3", das::SideEffects::none, "raylib_make_vector3");
        das::addExtern<DAS_BIND_FUN(raylib_make_color), das::SimNode_ExtFuncCallAndCopyOrMove>(
            *this, lib, "make_color", das::SideEffects::none, "raylib_make_color");
        das::addExtern<DAS_BIND_FUN(raylib_make_rectangle), das::SimNode_ExtFuncCallAndCopyOrMove>(
            *this, lib, "make_rectangle", das::SideEffects::none, "raylib_make_rectangle");

        // ── Preset color constants (struct returns need CopyOrMove) ──────────
        das::addExtern<DAS_BIND_FUN(raylib_color_lightgray), das::SimNode_ExtFuncCallAndCopyOrMove>(
            *this, lib, "LIGHTGRAY", das::SideEffects::none, "raylib_color_lightgray");
        das::addExtern<DAS_BIND_FUN(raylib_color_gray), das::SimNode_ExtFuncCallAndCopyOrMove>(
            *this, lib, "GRAY", das::SideEffects::none, "raylib_color_gray");
        das::addExtern<DAS_BIND_FUN(raylib_color_darkgray), das::SimNode_ExtFuncCallAndCopyOrMove>(
            *this, lib, "DARKGRAY", das::SideEffects::none, "raylib_color_darkgray");
        das::addExtern<DAS_BIND_FUN(raylib_color_yellow), das::SimNode_ExtFuncCallAndCopyOrMove>(
            *this, lib, "YELLOW", das::SideEffects::none, "raylib_color_yellow");
        das::addExtern<DAS_BIND_FUN(raylib_color_gold), das::SimNode_ExtFuncCallAndCopyOrMove>(
            *this, lib, "GOLD", das::SideEffects::none, "raylib_color_gold");
        das::addExtern<DAS_BIND_FUN(raylib_color_orange), das::SimNode_ExtFuncCallAndCopyOrMove>(
            *this, lib, "ORANGE", das::SideEffects::none, "raylib_color_orange");
        das::addExtern<DAS_BIND_FUN(raylib_color_pink), das::SimNode_ExtFuncCallAndCopyOrMove>(
            *this, lib, "PINK", das::SideEffects::none, "raylib_color_pink");
        das::addExtern<DAS_BIND_FUN(raylib_color_red), das::SimNode_ExtFuncCallAndCopyOrMove>(
            *this, lib, "RED", das::SideEffects::none, "raylib_color_red");
        das::addExtern<DAS_BIND_FUN(raylib_color_maroon), das::SimNode_ExtFuncCallAndCopyOrMove>(
            *this, lib, "MAROON", das::SideEffects::none, "raylib_color_maroon");
        das::addExtern<DAS_BIND_FUN(raylib_color_green), das::SimNode_ExtFuncCallAndCopyOrMove>(
            *this, lib, "GREEN", das::SideEffects::none, "raylib_color_green");
        das::addExtern<DAS_BIND_FUN(raylib_color_lime), das::SimNode_ExtFuncCallAndCopyOrMove>(
            *this, lib, "LIME", das::SideEffects::none, "raylib_color_lime");
        das::addExtern<DAS_BIND_FUN(raylib_color_darkgreen), das::SimNode_ExtFuncCallAndCopyOrMove>(
            *this, lib, "DARKGREEN", das::SideEffects::none, "raylib_color_darkgreen");
        das::addExtern<DAS_BIND_FUN(raylib_color_skyblue), das::SimNode_ExtFuncCallAndCopyOrMove>(
            *this, lib, "SKYBLUE", das::SideEffects::none, "raylib_color_skyblue");
        das::addExtern<DAS_BIND_FUN(raylib_color_blue), das::SimNode_ExtFuncCallAndCopyOrMove>(
            *this, lib, "BLUE", das::SideEffects::none, "raylib_color_blue");
        das::addExtern<DAS_BIND_FUN(raylib_color_darkblue), das::SimNode_ExtFuncCallAndCopyOrMove>(
            *this, lib, "DARKBLUE", das::SideEffects::none, "raylib_color_darkblue");
        das::addExtern<DAS_BIND_FUN(raylib_color_purple), das::SimNode_ExtFuncCallAndCopyOrMove>(
            *this, lib, "PURPLE", das::SideEffects::none, "raylib_color_purple");
        das::addExtern<DAS_BIND_FUN(raylib_color_violet), das::SimNode_ExtFuncCallAndCopyOrMove>(
            *this, lib, "VIOLET", das::SideEffects::none, "raylib_color_violet");
        das::addExtern<DAS_BIND_FUN(raylib_color_darkpurple), das::SimNode_ExtFuncCallAndCopyOrMove>(
            *this, lib, "DARKPURPLE", das::SideEffects::none, "raylib_color_darkpurple");
        das::addExtern<DAS_BIND_FUN(raylib_color_beige), das::SimNode_ExtFuncCallAndCopyOrMove>(
            *this, lib, "BEIGE", das::SideEffects::none, "raylib_color_beige");
        das::addExtern<DAS_BIND_FUN(raylib_color_brown), das::SimNode_ExtFuncCallAndCopyOrMove>(
            *this, lib, "BROWN", das::SideEffects::none, "raylib_color_brown");
        das::addExtern<DAS_BIND_FUN(raylib_color_darkbrown), das::SimNode_ExtFuncCallAndCopyOrMove>(
            *this, lib, "DARKBROWN", das::SideEffects::none, "raylib_color_darkbrown");
        das::addExtern<DAS_BIND_FUN(raylib_color_white), das::SimNode_ExtFuncCallAndCopyOrMove>(
            *this, lib, "WHITE", das::SideEffects::none, "raylib_color_white");
        das::addExtern<DAS_BIND_FUN(raylib_color_black), das::SimNode_ExtFuncCallAndCopyOrMove>(
            *this, lib, "BLACK", das::SideEffects::none, "raylib_color_black");
        das::addExtern<DAS_BIND_FUN(raylib_color_blank), das::SimNode_ExtFuncCallAndCopyOrMove>(
            *this, lib, "BLANK", das::SideEffects::none, "raylib_color_blank");
        das::addExtern<DAS_BIND_FUN(raylib_color_magenta), das::SimNode_ExtFuncCallAndCopyOrMove>(
            *this, lib, "MAGENTA", das::SideEffects::none, "raylib_color_magenta");
        das::addExtern<DAS_BIND_FUN(raylib_color_raywhite), das::SimNode_ExtFuncCallAndCopyOrMove>(
            *this, lib, "RAYWHITE", das::SideEffects::none, "raylib_color_raywhite");

        // ── Manual wrappers for struct-parameter functions ──────────────────
        das::addExtern<DAS_BIND_FUN(raylib_clear_background)>(
            *this, lib, "ClearBackground", das::SideEffects::modifyExternal, "raylib_clear_background");
        das::addExtern<DAS_BIND_FUN(raylib_get_mouse_delta), das::SimNode_ExtFuncCallAndCopyOrMove>(
            *this, lib, "GetMouseDelta", das::SideEffects::modifyExternal, "raylib_get_mouse_delta");
        das::addExtern<DAS_BIND_FUN(raylib_vector3_rotate_by_axis_angle), das::SimNode_ExtFuncCallAndCopyOrMove>(
            *this, lib, "Vector3RotateByAxisAngle", das::SideEffects::none, "raylib_vector3_rotate_by_axis_angle");
        das::addExtern<DAS_BIND_FUN(raylib_vector3_length)>(*this, lib, "Vector3Length", das::SideEffects::none,
                                                            "raylib_vector3_length");
        das::addExtern<DAS_BIND_FUN(raylib_vector3_scale), das::SimNode_ExtFuncCallAndCopyOrMove>(
            *this, lib, "Vector3Scale", das::SideEffects::none, "raylib_vector3_scale");
        das::addExtern<DAS_BIND_FUN(raylib_vector3_add), das::SimNode_ExtFuncCallAndCopyOrMove>(
            *this, lib, "Vector3Add", das::SideEffects::none, "raylib_vector3_add");
        das::addExtern<DAS_BIND_FUN(raylib_vector3_subtract), das::SimNode_ExtFuncCallAndCopyOrMove>(
            *this, lib, "Vector3Subtract", das::SideEffects::none, "raylib_vector3_subtract");
        das::addExtern<DAS_BIND_FUN(raylib_vector3_cross_product), das::SimNode_ExtFuncCallAndCopyOrMove>(
            *this, lib, "Vector3CrossProduct", das::SideEffects::none, "raylib_vector3_cross_product");
        das::addExtern<DAS_BIND_FUN(raylib_vector3_normalize), das::SimNode_ExtFuncCallAndCopyOrMove>(
            *this, lib, "Vector3Normalize", das::SideEffects::none, "raylib_vector3_normalize");
        das::addExtern<DAS_BIND_FUN(raylib_begin_mode_3d)>(*this, lib, "BeginMode3D", das::SideEffects::modifyExternal,
                                                           "raylib_begin_mode_3d");
        das::addExtern<DAS_BIND_FUN(raylib_draw_grid)>(*this, lib, "DrawGrid", das::SideEffects::modifyExternal,
                                                       "raylib_draw_grid");
        das::addExtern<DAS_BIND_FUN(raylib_draw_cube_v)>(*this, lib, "DrawCubeV", das::SideEffects::modifyExternal,
                                                         "raylib_draw_cube_v");
        das::addExtern<DAS_BIND_FUN(raylib_draw_cube_wires_v)>(
            *this, lib, "DrawCubeWiresV", das::SideEffects::modifyExternal, "raylib_draw_cube_wires_v");
        das::addExtern<DAS_BIND_FUN(raylib_draw_sphere)>(*this, lib, "DrawSphere", das::SideEffects::modifyExternal,
                                                         "raylib_draw_sphere");
        das::addExtern<DAS_BIND_FUN(raylib_fade), das::SimNode_ExtFuncCallAndCopyOrMove>(
            *this, lib, "Fade", das::SideEffects::none, "raylib_fade");
        das::addExtern<DAS_BIND_FUN(raylib_draw_rectangle_lines)>(
            *this, lib, "DrawRectangleLines", das::SideEffects::modifyExternal, "raylib_draw_rectangle_lines");
        das::addExtern<DAS_BIND_FUN(raylib_draw_rectangle)>(*this, lib, "DrawRectangle",
                                                            das::SideEffects::modifyExternal, "raylib_draw_rectangle");
        das::addExtern<DAS_BIND_FUN(raylib_draw_text)>(*this, lib, "DrawText", das::SideEffects::modifyExternal,
                                                       "raylib_draw_text");

        //compileBuiltinModule("raylib.das", raylib_das, sizeof(raylib_das));
        //compileBuiltinModule("raylib_helpers.das", raylib_helpers_das, sizeof(raylib_helpers_das));

// ── Generated: enums, extra structs, all RLAPI functions ─────────────
// NOTE: Some functions are commented out because they take or return struct types
// that need special wrappers. See manual wrappers above.
#include "generated/module_raylib_register.inc"
    }

    virtual das::ModuleAotType aotRequire(das::TextWriter &tw) const override
    {
        tw << "#include \"raylib.h\"\n";
        return das::ModuleAotType::cpp;
    }
};

REGISTER_MODULE(Module_raylib);
