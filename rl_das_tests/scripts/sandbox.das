options gen2
require raylib
// require raylib_window

let GRAVITY : float = 32.0
let MOVE_SPEED : float = 10.0
let SPRINT_SPEED : float = 22.0
let JUMP_FORCE : float = 12.0
let MOUSE_SENS : float = 0.003
let HALF_PI : float = 1.57079632679
let KEY_W_I : int = 87
let KEY_S_I : int = 83
let KEY_D_I : int = 68
let KEY_A_I : int = 65
let KEY_SPACE_I : int = 32
let KEY_LEFT_CONTROL_I : int = 341
let KEY_LEFT_SHIFT_I : int = 340

var playerPos : Vector3 = make_vector3(0.0, 5.0, 0.0)
var playerVelY : float = 0.0
var grounded : bool = true
var yaw : float = 0.0
var pitch : float = 0.0
var camera : Camera3D
let worldUp = make_vector3(0.0, 1.0, 0.0)

[export]
def sandbox() : void {
    InitWindow(800, 450, "raylib [core] example - 3d camera fps (das)")
    DisableCursor()
    SetTargetFPS(60)
}

[export]
def hot_recompile() : void {
    if (!IsWindowReady()) {
        InitWindow(800, 450, "raylib [core] example - 3d camera fps (das)")
        DisableCursor()
        SetTargetFPS(60)
    }

    playerPos = make_vector3(0.0, 0.0, 0.0)
    playerVelY = 0.0
    grounded = true
    yaw = 0.0
    pitch = 0.0

    camera.position = make_vector3(0.0, 1.5, 0.0)
    camera.target = make_vector3(0.0, 1.5, -1.0)
    camera.up = make_vector3(0.0, 1.0, 0.0)
    camera.fovy = 60.0
    camera.projection = 0
}

[export]
def hot_recompile_loop() : void {
    let dt = GetFrameTime()

    let mouse = GetMouseDelta()
    yaw -= mouse.x * MOUSE_SENS
    pitch += mouse.y * MOUSE_SENS
    if (pitch < -HALF_PI + 0.001) { pitch = -HALF_PI + 0.001; }
    if (pitch > HALF_PI - 0.001) { pitch = HALF_PI - 0.001; }

    var forward = Vector3RotateByAxisAngle(make_vector3(0.0, 0.0, -1.0), worldUp, yaw)
    var right = Vector3Normalize(Vector3CrossProduct(forward, worldUp))

    var move = make_vector3(0.0, 0.0, 0.0)
    if (IsKeyDown(KEY_W_I)) { move = Vector3Add(move, forward); }
    if (IsKeyDown(KEY_S_I)) { move = Vector3Subtract(move, forward); }
    if (IsKeyDown(KEY_D_I)) { move = Vector3Add(move, right); }
    if (IsKeyDown(KEY_A_I)) { move = Vector3Subtract(move, right); }

    move.y = 0.0
    let moveLen = Vector3Length(move)
    if (moveLen > 0.0) {
        move = Vector3Scale(move, 1.0 / moveLen)
        var speed : float
        if (IsKeyDown(KEY_LEFT_CONTROL_I)) {
            speed = 5.0;
        } else {
            if (IsKeyDown(KEY_LEFT_SHIFT_I)) {
                speed = SPRINT_SPEED
            } else {
                speed = MOVE_SPEED;
            }
        }
        playerPos = Vector3Add(playerPos, Vector3Scale(move, speed * dt))
    }

    if (grounded && IsKeyPressed(KEY_SPACE_I)) {
        playerVelY = JUMP_FORCE
        grounded = false
    }

    if (!grounded) { playerVelY -= GRAVITY * dt; }
    playerPos.y += playerVelY * dt
    if (playerPos.y <= 0.0) {
        playerPos.y = 0.0
        playerVelY = 0.0
        grounded = true
    }

    camera.position = make_vector3(playerPos.x, playerPos.y + 1.5, playerPos.z)

    let pitchAxis = Vector3Normalize(Vector3CrossProduct(forward, worldUp))
    let viewDir = Vector3RotateByAxisAngle(forward, pitchAxis, -pitch)
    camera.target = Vector3Add(camera.position, viewDir)

    BeginDrawing()
        let bg = RAYWHITE()
        ClearBackground(bg.r, bg.g, bg.b, bg.a)

        BeginMode3D(camera)
            DrawGrid(100, 5.0)

            DrawCubeV(make_vector3(16.0, 16.0, 16.0), make_vector3(16.0, 32.0, 16.0), SKYBLUE())
            DrawCubeWiresV(make_vector3(16.0, 16.0, 16.0), make_vector3(16.0, 32.0, 16.0), DARKBLUE())

            DrawCubeV(make_vector3(-16.0, 16.0, 16.0), make_vector3(16.0, 32.0, 16.0), SKYBLUE())
            DrawCubeWiresV(make_vector3(-16.0, 16.0, 16.0), make_vector3(16.0, 32.0, 16.0), DARKBLUE())

            DrawCubeV(make_vector3(-16.0, 16.0, -16.0), make_vector3(16.0, 32.0, 16.0), SKYBLUE())
            DrawCubeWiresV(make_vector3(-16.0, 16.0, -16.0), make_vector3(16.0, 32.0, 16.0), DARKBLUE())

            DrawCubeV(make_vector3(16.0, 16.0, -16.0), make_vector3(16.0, 32.0, 16.0), SKYBLUE())
            DrawCubeWiresV(make_vector3(16.0, 16.0, -16.0), make_vector3(16.0, 32.0, 16.0), DARKBLUE())

            DrawSphere(make_vector3(300.0, 300.0, 0.0), 100.0, RED())
        EndMode3D()

        DrawRectangle(5, 5, 330, 60, Fade(SKYBLUE(), 0.5))
        DrawRectangleLines(5, 5, 330, 60, BLUE())
        DrawText("Camera controls:", 15, 15, 10, BLACK())
        DrawText("- Move: W, A, S, D, Space, Left-Ctrl", 15, 30, 10, BLACK())
        DrawText("- Look around: mouse", 15, 45, 10, BLACK())
    EndDrawing()
}

[export]
def hot_recompile_shutdown() : void {
    // CloseWindow()
}














def standalone() : void {
    hot_recompile()

    while (!WindowShouldClose()) {
        hot_recompile_loop()
    }

    CloseWindow()
}