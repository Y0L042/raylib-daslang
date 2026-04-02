options gen2

// Raylib DASLang Module
// High-level daslang wrappers over the raw raylib C API.
// The raw API (all RLAPI functions, enums, types) is available directly
// after `require raylib` — these are just ergonomic helpers.
//
// Usage:
//   require raylib
//
//   [export]
//   def main()
//       InitWindow(800, 600, "Hello, Raylib!")
//       SetTargetFPS(60)
//       while (!WindowShouldClose())
//           BeginDrawing()
//           ClearBackground(RAYWHITE())
//           DrawText("Hello from daslang!", 10, 10, 20, BLACK())
//           EndDrawing()
//       CloseWindow()

// ============================================================================
// TYPEDEFS
// ============================================================================
 

// ============================================================================
// WINDOW HELPERS
// ============================================================================

def window_should_close() : bool {
    return WindowShouldClose()
}

def is_window_ready() : bool {
    return IsWindowReady()
}

def is_window_focused() : bool {
    return IsWindowFocused()
}

def is_window_minimized() : bool {
    return IsWindowMinimized()
}

def is_window_maximized() : bool {
    return IsWindowMaximized()
}

def is_window_hidden() : bool {
    return IsWindowHidden()
}

def is_window_fullscreen() : bool {
    return IsWindowFullscreen()
}

def get_screen_width() : int {
    return GetScreenWidth()
}

def get_screen_height() : int {
    return GetScreenHeight()
}

// ============================================================================
// DRAWING HELPERS
// ============================================================================

def begin_drawing() {
    BeginDrawing()
}

def end_drawing() {
    EndDrawing()
}

def clear_background(color : Color) {
    ClearBackground(color)
}

def draw_fps(posX : int; posY : int) {
    DrawFPS(posX, posY)
}

def draw_text(text : string; posX : int; posY : int; fontSize : int; color : Color) {
    DrawText(text, posX, posY, fontSize, color)
}

def draw_rectangle(posX : int; posY : int; width : int; height : int; color : Color) {
    DrawRectangle(posX, posY, width, height, color)
}

def draw_rectangle_lines(posX : int; posY : int; width : int; height : int; color : Color) {
    DrawRectangleLines(posX, posY, width, height, color)
}

def draw_circle(centerX : int; centerY : int; radius : float; color : Color) {
    DrawCircle(centerX, centerY, radius, color)
}

def draw_circle_lines(centerX : int; centerY : int; radius : float; color : Color) {
    DrawCircleLines(centerX, centerY, radius, color)
}

def draw_line(startX : int; startY : int; endX : int; endY : int; color : Color) {
    DrawLine(startX, startY, endX, endY, color)
}

def draw_line_v(startPos : Vector2; endPos : Vector2; color : Color) {
    DrawLineV(startPos, endPos, color)
}

def draw_pixel(posX : int; posY : int; color : Color) {
    DrawPixel(posX, posY, color)
}

// ============================================================================
// INPUT HELPERS
// ============================================================================

def is_key_pressed(key : int) : bool {
    return IsKeyPressed(key)
}

def is_key_down(key : int) : bool {
    return IsKeyDown(key)
}

def is_key_released(key : int) : bool {
    return IsKeyReleased(key)
}

def is_key_up(key : int) : bool {
    return IsKeyUp(key)
}

def get_key_pressed() : int {
    return GetKeyPressed()
}

def is_mouse_button_pressed(button : int) : bool {
    return IsMouseButtonPressed(button)
}

def is_mouse_button_down(button : int) : bool {
    return IsMouseButtonDown(button)
}

def is_mouse_button_released(button : int) : bool {
    return IsMouseButtonReleased(button)
}

def get_mouse_position() : Vector2 {
    return GetMousePosition()
}

def get_mouse_x() : int {
    return GetMouseX()
}

def get_mouse_y() : int {
    return GetMouseY()
}

// ============================================================================
// TIMING HELPERS
// ============================================================================

def get_frame_time() : float {
    return GetFrameTime()
}

def get_time() : double {
    return GetTime()
}

def get_fps() : int {
    return GetFPS()
}

// ============================================================================
// RESOURCE HELPERS (string-argument convenience wrappers)
// ============================================================================

def load_texture(fileName : string) : Texture2D {
    return LoadTexture(fileName)
}

def unload_texture(texture : Texture2D) {
    UnloadTexture(texture)
}

def load_image(fileName : string) : Image {
    return LoadImage(fileName)
}

def unload_image(image : Image) {
    UnloadImage(image)
}

def load_sound(fileName : string) : Sound {
    return LoadSound(fileName)
}

def unload_sound(sound : Sound) {
    UnloadSound(sound)
}

def load_music_stream(fileName : string) : Music {
    return LoadMusicStream(fileName)
}

def unload_music_stream(music : Music) {
    UnloadMusicStream(music)
}

def load_font(fileName : string) : Font {
    return LoadFont(fileName)
}

def unload_font(font : Font) {
    UnloadFont(font)
}

def load_shader(vsFileName : string; fsFileName : string) : Shader {
    return LoadShader(vsFileName, fsFileName)
}

def unload_shader(shader : Shader) {
    UnloadShader(shader)
}

def load_model(fileName : string) : Model {
    return LoadModel(fileName)
}

def unload_model(model : Model) {
    UnloadModel(model)
}

// BEGIN GENERATED TYPEDEFS


// END GENERATED TYPEDEFS

// BEGIN GENERATED ENUM CONSTANTS

// ConfigFlags
let FLAG_VSYNC_HINT : int = 0x00000040
let FLAG_FULLSCREEN_MODE : int = 0x00000002
let FLAG_WINDOW_RESIZABLE : int = 0x00000004
let FLAG_WINDOW_UNDECORATED : int = 0x00000008
let FLAG_WINDOW_HIDDEN : int = 0x00000080
let FLAG_WINDOW_MINIMIZED : int = 0x00000200
let FLAG_WINDOW_MAXIMIZED : int = 0x00000400
let FLAG_WINDOW_UNFOCUSED : int = 0x00000800
let FLAG_WINDOW_TOPMOST : int = 0x00001000
let FLAG_WINDOW_ALWAYS_RUN : int = 0x00000100
let FLAG_WINDOW_TRANSPARENT : int = 0x00000010
let FLAG_WINDOW_HIGHDPI : int = 0x00002000
let FLAG_WINDOW_MOUSE_PASSTHROUGH : int = 0x00004000
let FLAG_BORDERLESS_WINDOWED_MODE : int = 0x00008000
let FLAG_MSAA_4X_HINT : int = 0x00000020
let FLAG_INTERLACED_HINT : int = 0x00010000

// TraceLogLevel
let LOG_ALL : int = 0
let LOG_TRACE : int = 1
let LOG_DEBUG : int = 2
let LOG_INFO : int = 3
let LOG_WARNING : int = 4
let LOG_ERROR : int = 5
let LOG_FATAL : int = 6
let LOG_NONE : int = 7

// KeyboardKey
let KEY_NULL : int = 0
let KEY_APOSTROPHE : int = 39
let KEY_COMMA : int = 44
let KEY_MINUS : int = 45
let KEY_PERIOD : int = 46
let KEY_SLASH : int = 47
let KEY_ZERO : int = 48
let KEY_ONE : int = 49
let KEY_TWO : int = 50
let KEY_THREE : int = 51
let KEY_FOUR : int = 52
let KEY_FIVE : int = 53
let KEY_SIX : int = 54
let KEY_SEVEN : int = 55
let KEY_EIGHT : int = 56
let KEY_NINE : int = 57
let KEY_SEMICOLON : int = 59
let KEY_EQUAL : int = 61
let KEY_A : int = 65
let KEY_B : int = 66
let KEY_C : int = 67
let KEY_D : int = 68
let KEY_E : int = 69
let KEY_F : int = 70
let KEY_G : int = 71
let KEY_H : int = 72
let KEY_I : int = 73
let KEY_J : int = 74
let KEY_K : int = 75
let KEY_L : int = 76
let KEY_M : int = 77
let KEY_N : int = 78
let KEY_O : int = 79
let KEY_P : int = 80
let KEY_Q : int = 81
let KEY_R : int = 82
let KEY_S : int = 83
let KEY_T : int = 84
let KEY_U : int = 85
let KEY_V : int = 86
let KEY_W : int = 87
let KEY_X : int = 88
let KEY_Y : int = 89
let KEY_Z : int = 90
let KEY_LEFT_BRACKET : int = 91
let KEY_BACKSLASH : int = 92
let KEY_RIGHT_BRACKET : int = 93
let KEY_GRAVE : int = 96
let KEY_SPACE : int = 32
let KEY_ESCAPE : int = 256
let KEY_ENTER : int = 257
let KEY_TAB : int = 258
let KEY_BACKSPACE : int = 259
let KEY_INSERT : int = 260
let KEY_DELETE : int = 261
let KEY_RIGHT : int = 262
let KEY_LEFT : int = 263
let KEY_DOWN : int = 264
let KEY_UP : int = 265
let KEY_PAGE_UP : int = 266
let KEY_PAGE_DOWN : int = 267
let KEY_HOME : int = 268
let KEY_END : int = 269
let KEY_CAPS_LOCK : int = 280
let KEY_SCROLL_LOCK : int = 281
let KEY_NUM_LOCK : int = 282
let KEY_PRINT_SCREEN : int = 283
let KEY_PAUSE : int = 284
let KEY_F1 : int = 290
let KEY_F2 : int = 291
let KEY_F3 : int = 292
let KEY_F4 : int = 293
let KEY_F5 : int = 294
let KEY_F6 : int = 295
let KEY_F7 : int = 296
let KEY_F8 : int = 297
let KEY_F9 : int = 298
let KEY_F10 : int = 299
let KEY_F11 : int = 300
let KEY_F12 : int = 301
let KEY_LEFT_SHIFT : int = 340
let KEY_LEFT_CONTROL : int = 341
let KEY_LEFT_ALT : int = 342
let KEY_LEFT_SUPER : int = 343
let KEY_RIGHT_SHIFT : int = 344
let KEY_RIGHT_CONTROL : int = 345
let KEY_RIGHT_ALT : int = 346
let KEY_RIGHT_SUPER : int = 347
let KEY_KB_MENU : int = 348
let KEY_KP_0 : int = 320
let KEY_KP_1 : int = 321
let KEY_KP_2 : int = 322
let KEY_KP_3 : int = 323
let KEY_KP_4 : int = 324
let KEY_KP_5 : int = 325
let KEY_KP_6 : int = 326
let KEY_KP_7 : int = 327
let KEY_KP_8 : int = 328
let KEY_KP_9 : int = 329
let KEY_KP_DECIMAL : int = 330
let KEY_KP_DIVIDE : int = 331
let KEY_KP_MULTIPLY : int = 332
let KEY_KP_SUBTRACT : int = 333
let KEY_KP_ADD : int = 334
let KEY_KP_ENTER : int = 335
let KEY_KP_EQUAL : int = 336
let KEY_BACK : int = 4
let KEY_MENU : int = 5
let KEY_VOLUME_UP : int = 24
let KEY_VOLUME_DOWN : int = 25

// MouseButton
let MOUSE_BUTTON_LEFT : int = 0
let MOUSE_BUTTON_RIGHT : int = 1
let MOUSE_BUTTON_MIDDLE : int = 2
let MOUSE_BUTTON_SIDE : int = 3
let MOUSE_BUTTON_EXTRA : int = 4
let MOUSE_BUTTON_FORWARD : int = 5
let MOUSE_BUTTON_BACK : int = 6

// MouseCursor
let MOUSE_CURSOR_DEFAULT : int = 0
let MOUSE_CURSOR_ARROW : int = 1
let MOUSE_CURSOR_IBEAM : int = 2
let MOUSE_CURSOR_CROSSHAIR : int = 3
let MOUSE_CURSOR_POINTING_HAND : int = 4
let MOUSE_CURSOR_RESIZE_EW : int = 5
let MOUSE_CURSOR_RESIZE_NS : int = 6
let MOUSE_CURSOR_RESIZE_NWSE : int = 7
let MOUSE_CURSOR_RESIZE_NESW : int = 8
let MOUSE_CURSOR_RESIZE_ALL : int = 9
let MOUSE_CURSOR_NOT_ALLOWED : int = 10

// GamepadButton
let GAMEPAD_BUTTON_UNKNOWN : int = 0
let GAMEPAD_BUTTON_LEFT_FACE_UP : int = 1
let GAMEPAD_BUTTON_LEFT_FACE_RIGHT : int = 2
let GAMEPAD_BUTTON_LEFT_FACE_DOWN : int = 3
let GAMEPAD_BUTTON_LEFT_FACE_LEFT : int = 4
let GAMEPAD_BUTTON_RIGHT_FACE_UP : int = 5
let GAMEPAD_BUTTON_RIGHT_FACE_RIGHT : int = 6
let GAMEPAD_BUTTON_RIGHT_FACE_DOWN : int = 7
let GAMEPAD_BUTTON_RIGHT_FACE_LEFT : int = 8
let GAMEPAD_BUTTON_LEFT_TRIGGER_1 : int = 9
let GAMEPAD_BUTTON_LEFT_TRIGGER_2 : int = 10
let GAMEPAD_BUTTON_RIGHT_TRIGGER_1 : int = 11
let GAMEPAD_BUTTON_RIGHT_TRIGGER_2 : int = 12
let GAMEPAD_BUTTON_MIDDLE_LEFT : int = 13
let GAMEPAD_BUTTON_MIDDLE : int = 14
let GAMEPAD_BUTTON_MIDDLE_RIGHT : int = 15
let GAMEPAD_BUTTON_LEFT_THUMB : int = 16
let GAMEPAD_BUTTON_RIGHT_THUMB : int = 17

// GamepadAxis
let GAMEPAD_AXIS_LEFT_X : int = 0
let GAMEPAD_AXIS_LEFT_Y : int = 1
let GAMEPAD_AXIS_RIGHT_X : int = 2
let GAMEPAD_AXIS_RIGHT_Y : int = 3
let GAMEPAD_AXIS_LEFT_TRIGGER : int = 4
let GAMEPAD_AXIS_RIGHT_TRIGGER : int = 5

// MaterialMapIndex
let MATERIAL_MAP_ALBEDO : int = 0
let MATERIAL_MAP_METALNESS : int = 1
let MATERIAL_MAP_NORMAL : int = 2
let MATERIAL_MAP_ROUGHNESS : int = 3
let MATERIAL_MAP_OCCLUSION : int = 4
let MATERIAL_MAP_EMISSION : int = 5
let MATERIAL_MAP_HEIGHT : int = 6
let MATERIAL_MAP_CUBEMAP : int = 7
let MATERIAL_MAP_IRRADIANCE : int = 8
let MATERIAL_MAP_PREFILTER : int = 9
let MATERIAL_MAP_BRDF : int = 10

// ShaderLocationIndex
let SHADER_LOC_VERTEX_POSITION : int = 0
let SHADER_LOC_VERTEX_TEXCOORD01 : int = 1
let SHADER_LOC_VERTEX_TEXCOORD02 : int = 2
let SHADER_LOC_VERTEX_NORMAL : int = 3
let SHADER_LOC_VERTEX_TANGENT : int = 4
let SHADER_LOC_VERTEX_COLOR : int = 5
let SHADER_LOC_MATRIX_MVP : int = 6
let SHADER_LOC_MATRIX_VIEW : int = 7
let SHADER_LOC_MATRIX_PROJECTION : int = 8
let SHADER_LOC_MATRIX_MODEL : int = 9
let SHADER_LOC_MATRIX_NORMAL : int = 10
let SHADER_LOC_VECTOR_VIEW : int = 11
let SHADER_LOC_COLOR_DIFFUSE : int = 12
let SHADER_LOC_COLOR_SPECULAR : int = 13
let SHADER_LOC_COLOR_AMBIENT : int = 14
let SHADER_LOC_MAP_ALBEDO : int = 15
let SHADER_LOC_MAP_METALNESS : int = 16
let SHADER_LOC_MAP_NORMAL : int = 17
let SHADER_LOC_MAP_ROUGHNESS : int = 18
let SHADER_LOC_MAP_OCCLUSION : int = 19
let SHADER_LOC_MAP_EMISSION : int = 20
let SHADER_LOC_MAP_HEIGHT : int = 21
let SHADER_LOC_MAP_CUBEMAP : int = 22
let SHADER_LOC_MAP_IRRADIANCE : int = 23
let SHADER_LOC_MAP_PREFILTER : int = 24
let SHADER_LOC_MAP_BRDF : int = 25
let SHADER_LOC_VERTEX_BONEIDS : int = 26
let SHADER_LOC_VERTEX_BONEWEIGHTS : int = 27
let SHADER_LOC_MATRIX_BONETRANSFORMS : int = 28
let SHADER_LOC_VERTEX_INSTANCETRANSFORM : int = 29

// ShaderUniformDataType
let SHADER_UNIFORM_FLOAT : int = 0
let SHADER_UNIFORM_VEC2 : int = 1
let SHADER_UNIFORM_VEC3 : int = 2
let SHADER_UNIFORM_VEC4 : int = 3
let SHADER_UNIFORM_INT : int = 4
let SHADER_UNIFORM_IVEC2 : int = 5
let SHADER_UNIFORM_IVEC3 : int = 6
let SHADER_UNIFORM_IVEC4 : int = 7
let SHADER_UNIFORM_UINT : int = 8
let SHADER_UNIFORM_UIVEC2 : int = 9
let SHADER_UNIFORM_UIVEC3 : int = 10
let SHADER_UNIFORM_UIVEC4 : int = 11
let SHADER_UNIFORM_SAMPLER2D : int = 12

// ShaderAttributeDataType
let SHADER_ATTRIB_FLOAT : int = 0
let SHADER_ATTRIB_VEC2 : int = 1
let SHADER_ATTRIB_VEC3 : int = 2
let SHADER_ATTRIB_VEC4 : int = 3

// PixelFormat
let PIXELFORMAT_UNCOMPRESSED_GRAYSCALE : int = 1
let PIXELFORMAT_UNCOMPRESSED_GRAY_ALPHA : int = 1
let PIXELFORMAT_UNCOMPRESSED_R5G6B5 : int = 2
let PIXELFORMAT_UNCOMPRESSED_R8G8B8 : int = 3
let PIXELFORMAT_UNCOMPRESSED_R5G5B5A1 : int = 4
let PIXELFORMAT_UNCOMPRESSED_R4G4B4A4 : int = 5
let PIXELFORMAT_UNCOMPRESSED_R8G8B8A8 : int = 6
let PIXELFORMAT_UNCOMPRESSED_R32 : int = 7
let PIXELFORMAT_UNCOMPRESSED_R32G32B32 : int = 8
let PIXELFORMAT_UNCOMPRESSED_R32G32B32A32 : int = 9
let PIXELFORMAT_UNCOMPRESSED_R16 : int = 10
let PIXELFORMAT_UNCOMPRESSED_R16G16B16 : int = 11
let PIXELFORMAT_UNCOMPRESSED_R16G16B16A16 : int = 12
let PIXELFORMAT_COMPRESSED_DXT1_RGB : int = 13
let PIXELFORMAT_COMPRESSED_DXT1_RGBA : int = 14
let PIXELFORMAT_COMPRESSED_DXT3_RGBA : int = 15
let PIXELFORMAT_COMPRESSED_DXT5_RGBA : int = 16
let PIXELFORMAT_COMPRESSED_ETC1_RGB : int = 17
let PIXELFORMAT_COMPRESSED_ETC2_RGB : int = 18
let PIXELFORMAT_COMPRESSED_ETC2_EAC_RGBA : int = 19
let PIXELFORMAT_COMPRESSED_PVRT_RGB : int = 20
let PIXELFORMAT_COMPRESSED_PVRT_RGBA : int = 21

// TextureFilter
let TEXTURE_FILTER_POINT : int = 0
let TEXTURE_FILTER_BILINEAR : int = 1
let TEXTURE_FILTER_TRILINEAR : int = 2
let TEXTURE_FILTER_ANISOTROPIC_4X : int = 3
let TEXTURE_FILTER_ANISOTROPIC_8X : int = 4
let TEXTURE_FILTER_ANISOTROPIC_16X : int = 5

// TextureWrap
let TEXTURE_WRAP_REPEAT : int = 0
let TEXTURE_WRAP_CLAMP : int = 1
let TEXTURE_WRAP_MIRROR_REPEAT : int = 2
let TEXTURE_WRAP_MIRROR_CLAMP : int = 3

// CubemapLayout
let CUBEMAP_LAYOUT_AUTO_DETECT : int = 0
let CUBEMAP_LAYOUT_LINE_VERTICAL : int = 1
let CUBEMAP_LAYOUT_LINE_HORIZONTAL : int = 2
let CUBEMAP_LAYOUT_CROSS_THREE_BY_FOUR : int = 3
let CUBEMAP_LAYOUT_CROSS_FOUR_BY_THREE : int = 4

// FontType
let FONT_DEFAULT : int = 0
let FONT_BITMAP : int = 1
let FONT_SDF : int = 2

// BlendMode
let BLEND_ALPHA : int = 0
let BLEND_ADDITIVE : int = 1
let BLEND_MULTIPLIED : int = 2
let BLEND_ADD_COLORS : int = 3
let BLEND_SUBTRACT_COLORS : int = 4
let BLEND_ALPHA_PREMULTIPLY : int = 5
let BLEND_CUSTOM : int = 6
let BLEND_CUSTOM_SEPARATE : int = 7

// Gesture
let GESTURE_NONE : int = 0
let GESTURE_TAP : int = 1
let GESTURE_DOUBLETAP : int = 2
let GESTURE_HOLD : int = 4
let GESTURE_DRAG : int = 8
let GESTURE_SWIPE_RIGHT : int = 16
let GESTURE_SWIPE_LEFT : int = 32
let GESTURE_SWIPE_UP : int = 64
let GESTURE_SWIPE_DOWN : int = 128
let GESTURE_PINCH_IN : int = 256
let GESTURE_PINCH_OUT : int = 512

// CameraMode
let CAMERA_CUSTOM : int = 0
let CAMERA_FREE : int = 1
let CAMERA_ORBITAL : int = 2
let CAMERA_FIRST_PERSON : int = 3
let CAMERA_THIRD_PERSON : int = 4

// CameraProjection
let CAMERA_PERSPECTIVE : int = 0
let CAMERA_ORTHOGRAPHIC : int = 1

// NPatchLayout
let NPATCH_NINE_PATCH : int = 0
let NPATCH_THREE_PATCH_VERTICAL : int = 1
let NPATCH_THREE_PATCH_HORIZONTAL : int = 2

// END GENERATED ENUM CONSTANTS
