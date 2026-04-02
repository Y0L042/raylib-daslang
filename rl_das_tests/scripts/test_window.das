// Raylib DASLang Test Suite - Window Tests

require raylib

def test_window_creation()
    print("=== Test: Window Creation ===")
    
    InitWindow(800, 600, "Raylib DASLang Window Test")
    
    if !IsWindowReady()
        print("ERROR: Window not ready")
        return
    
    print("✓ Window created successfully")
    print("  Screen width: {GetScreenWidth()}")
    print("  Screen height: {GetScreenHeight()}")
    
    CloseWindow()
    print("✓ Window closed successfully")

def test_window_properties()
    print("\n=== Test: Window Properties ===")
    
    InitWindow(800, 600, "Raylib DASLang Properties Test")
    
    print("✓ Window ready: {IsWindowReady()}")
    print("✓ Window focused: {IsWindowFocused()}")
    print("✓ Window minimized: {IsWindowMinimized()}")
    print("✓ Window maximized: {IsWindowMaximized()}")
    
    CloseWindow()

def run_tests()
    print("\n╔════════════════════════════════════════╗")
    print("║   Raylib DASLang Window Tests        ║")
    print("╚════════════════════════════════════════╝\n")
    
    test_window_creation()
    test_window_properties()
    
    print("\n✓ All window tests completed\n")
