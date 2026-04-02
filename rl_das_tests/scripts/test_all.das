options gen2

// Main test runner for raylib_das module
require raylib

require test_window
require test_drawing
require test_input

[export]
def main() {
    print("\n╔════════════════════════════════════════╗")
    print("║   Raylib DASLang Module Test Suite   ║")
    print("╚════════════════════════════════════════╝\n")
    
    // Run all test suites
    test_window::run_tests()
    test_drawing::run_tests()
    test_input::run_tests()
    
    print("\n╔════════════════════════════════════════╗")
    print("║        All Test Suites Completed       ║")
    print("╚════════════════════════════════════════╝\n")
}
