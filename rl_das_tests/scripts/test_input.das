// Raylib DASLang Test Suite - Input Tests

require raylib

def test_keyboard_input()
    print("=== Test: Keyboard Input ===")
    
    InitWindow(800, 600, "Raylib DASLang Input Test")
    SetTargetFPS(60)
    
    var key_pressed = false
    
    // Simulate checking for input
    for i in range(5)
        if WindowShouldClose()
            break
        
        BeginDrawing()
        ClearBackground(make_color(32u8, 32u8, 32u8, 255u8))
        
        // Check input
        if IsKeyPressed(KEY_SPACE)
            key_pressed = true
            print("  SPACE key pressed detected")
        
        if IsKeyDown(KEY_A)
            print("  A key is held down")
        
        EndDrawing()
    
    CloseWindow()
    print("✓ Keyboard input test completed")

def test_mouse_input()
    print("\n=== Test: Mouse Input ===")
    
    InitWindow(800, 600, "Raylib DASLang Mouse Test")
    SetTargetFPS(60)
    
    // Simulate checking mouse input
    for i in range(5)
        if WindowShouldClose()
            break
        
        BeginDrawing()
        ClearBackground(make_color(32u8, 32u8, 32u8, 255u8))
        
        let mouse_pos = GetMousePosition()
        print("  Mouse position: ({mouse_pos.x}, {mouse_pos.y})")
        
        if IsMouseButtonPressed(MOUSE_BUTTON_LEFT)
            print("  Left mouse button pressed")
        
        EndDrawing()
    
    CloseWindow()
    print("✓ Mouse input test completed")

// Define key codes (should come from generated raylib.das.inc)
let KEY_SPACE = 32
let KEY_A = 65
let MOUSE_BUTTON_LEFT = 0

def run_tests()
    print("\n╔════════════════════════════════════════╗")
    print("║   Raylib DASLang Input Tests         ║")
    print("╚════════════════════════════════════════╝\n")
    
    test_keyboard_input()
    test_mouse_input()
    
    print("\n✓ All input tests completed\n")
