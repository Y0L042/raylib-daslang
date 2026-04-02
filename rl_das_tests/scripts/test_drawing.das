// Raylib DASLang Test Suite - Drawing Tests

require raylib

def test_basic_drawing()
    print("=== Test: Basic Drawing ===")
    
    InitWindow(800, 600, "Raylib DASLang Drawing Test")
    SetTargetFPS(60)
    
    // Simulate a few frames of drawing
    for i in range(5)
        if WindowShouldClose()
            break
        
        BeginDrawing()
        ClearBackground(make_color(32u8, 32u8, 32u8, 255u8))
        
        // Draw some shapes
        DrawRectangle(100, 100, 200, 150, make_color(255u8, 0u8, 0u8, 255u8))
        DrawCircle(400, 300, 50, make_color(0u8, 255u8, 0u8, 255u8))
        DrawLine(0, 0, 800, 600, make_color(255u8, 255u8, 255u8, 255u8))
        
        EndDrawing()
        print("  Frame {i+1} drawn")
    
    CloseWindow()
    print("✓ Drawing test completed")

def run_tests()
    print("\n╔════════════════════════════════════════╗")
    print("║   Raylib DASLang Drawing Tests       ║")
    print("╚════════════════════════════════════════╝\n")
    
    test_basic_drawing()
    
    print("\n✓ All drawing tests completed\n")
