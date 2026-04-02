// Raylib DASLang Helpers
// Utility functions for common raylib patterns

// ============================================================================
// VECTOR HELPERS
// ============================================================================

def vector2_zero() : Vector2
    return make_vector2(0.0, 0.0)

def vector2_one() : Vector2
    return make_vector2(1.0, 1.0)

def vector2_add(v1 : Vector2; v2 : Vector2) : Vector2
    return make_vector2(v1.x + v2.x, v1.y + v2.y)

def vector2_subtract(v1 : Vector2; v2 : Vector2) : Vector2
    return make_vector2(v1.x - v2.x, v1.y - v2.y)

def vector2_scale(v : Vector2; scale : float) : Vector2
    return make_vector2(v.x * scale, v.y * scale)

def vector2_distance(v1 : Vector2; v2 : Vector2) : float
    let dx = v1.x - v2.x
    let dy = v1.y - v2.y
    return sqrt(dx * dx + dy * dy)

def vector3_zero() : Vector3
    return make_vector3(0.0, 0.0, 0.0)

def vector3_one() : Vector3
    return make_vector3(1.0, 1.0, 1.0)

def vector3_add(v1 : Vector3; v2 : Vector3) : Vector3
    return make_vector3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z)

def vector3_subtract(v1 : Vector3; v2 : Vector3) : Vector3
    return make_vector3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z)

// ============================================================================
// COLOR HELPERS
// ============================================================================

def color_red() : Color
    return make_color(255u8, 0u8, 0u8, 255u8)

def color_green() : Color
    return make_color(0u8, 255u8, 0u8, 255u8)

def color_blue() : Color
    return make_color(0u8, 0u8, 255u8, 255u8)

def color_white() : Color
    return make_color(255u8, 255u8, 255u8, 255u8)

def color_black() : Color
    return make_color(0u8, 0u8, 0u8, 255u8)

def color_gray() : Color
    return make_color(128u8, 128u8, 128u8, 255u8)

def color_clear() : Color
    return make_color(0u8, 0u8, 0u8, 0u8)

def color_fade(color : Color; alpha : float) : Color
    return make_color(color.r, color.g, color.b, uint8(clamp(alpha * 255.0, 0.0, 255.0)))

// ============================================================================
// RECTANGLE HELPERS
// ============================================================================

def rectangle_zero() : Rectangle
    return make_rectangle(0.0, 0.0, 0.0, 0.0)

def rectangle_from_pos_size(x : float; y : float; w : float; h : float) : Rectangle
    return make_rectangle(x, y, w, h)

def rectangle_overlaps(r1 : Rectangle; r2 : Rectangle) : bool
    return r1.x < r2.x + r2.width &&
           r1.x + r1.width > r2.x &&
           r1.y < r2.y + r2.height &&
           r1.y + r1.height > r2.y

def rectangle_contains_point(rect : Rectangle; point : Vector2) : bool
    return point.x >= rect.x &&
           point.x <= rect.x + rect.width &&
           point.y >= rect.y &&
           point.y <= rect.y + rect.height

// ============================================================================
// TIMING HELPERS
// ============================================================================

def should_close_window() : bool
    return WindowShouldClose()

// ============================================================================
// DEBUG
// ============================================================================

def log_info(message : string)
    print("INFO: {message}")

def log_warn(message : string)
    print("WARN: {message}")

def log_error(message : string)
    print("ERROR: {message}")
