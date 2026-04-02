// GENERATED — do not edit manually.
// Regenerate with: python3 tools/gen_raylib_bindings.py

// --- Enum registrations ---

addEnumeration(das::make_smart<EnumerationConfigFlags>());
addEnumeration(das::make_smart<EnumerationTraceLogLevel>());
addEnumeration(das::make_smart<EnumerationKeyboardKey>());
addEnumeration(das::make_smart<EnumerationMouseButton>());
addEnumeration(das::make_smart<EnumerationMouseCursor>());
addEnumeration(das::make_smart<EnumerationGamepadButton>());
addEnumeration(das::make_smart<EnumerationGamepadAxis>());
addEnumeration(das::make_smart<EnumerationMaterialMapIndex>());
addEnumeration(das::make_smart<EnumerationShaderLocationIndex>());
addEnumeration(das::make_smart<EnumerationShaderUniformDataType>());
addEnumeration(das::make_smart<EnumerationShaderAttributeDataType>());
addEnumeration(das::make_smart<EnumerationPixelFormat>());
addEnumeration(das::make_smart<EnumerationTextureFilter>());
addEnumeration(das::make_smart<EnumerationTextureWrap>());
addEnumeration(das::make_smart<EnumerationCubemapLayout>());
addEnumeration(das::make_smart<EnumerationFontType>());
addEnumeration(das::make_smart<EnumerationBlendMode>());
addEnumeration(das::make_smart<EnumerationGesture>());
addEnumeration(das::make_smart<EnumerationCameraMode>());
addEnumeration(das::make_smart<EnumerationCameraProjection>());
addEnumeration(das::make_smart<EnumerationNPatchLayout>());

// --- Extra struct annotation registrations ---

addAnnotation(das::make_smart<RaylibAutomationEventAnnotation>(lib));
addAnnotation(das::make_smart<RaylibAutomationEventListAnnotation>(lib));
addAnnotation(das::make_smart<RaylibFilePathListAnnotation>(lib));
addAnnotation(das::make_smart<RaylibModelSkeletonAnnotation>(lib));
addAnnotation(das::make_smart<RaylibVrDeviceInfoAnnotation>(lib));
addAnnotation(das::make_smart<RaylibVrStereoConfigAnnotation>(lib));

// --- Function registrations ---

das::addExtern<DAS_BIND_FUN(InitWindow)>(*this, lib, "InitWindow", das::SideEffects::modifyExternal, "InitWindow");
das::addExtern<DAS_BIND_FUN(CloseWindow)>(*this, lib, "CloseWindow", das::SideEffects::modifyExternal, "CloseWindow");
das::addExtern<DAS_BIND_FUN(WindowShouldClose)>(*this, lib, "WindowShouldClose", das::SideEffects::modifyExternal, "WindowShouldClose");
das::addExtern<DAS_BIND_FUN(IsWindowReady)>(*this, lib, "IsWindowReady", das::SideEffects::modifyExternal, "IsWindowReady");
das::addExtern<DAS_BIND_FUN(IsWindowFullscreen)>(*this, lib, "IsWindowFullscreen", das::SideEffects::modifyExternal, "IsWindowFullscreen");
das::addExtern<DAS_BIND_FUN(IsWindowHidden)>(*this, lib, "IsWindowHidden", das::SideEffects::modifyExternal, "IsWindowHidden");
das::addExtern<DAS_BIND_FUN(IsWindowMinimized)>(*this, lib, "IsWindowMinimized", das::SideEffects::modifyExternal, "IsWindowMinimized");
das::addExtern<DAS_BIND_FUN(IsWindowMaximized)>(*this, lib, "IsWindowMaximized", das::SideEffects::modifyExternal, "IsWindowMaximized");
das::addExtern<DAS_BIND_FUN(IsWindowFocused)>(*this, lib, "IsWindowFocused", das::SideEffects::modifyExternal, "IsWindowFocused");
das::addExtern<DAS_BIND_FUN(IsWindowResized)>(*this, lib, "IsWindowResized", das::SideEffects::modifyExternal, "IsWindowResized");
das::addExtern<DAS_BIND_FUN(IsWindowState)>(*this, lib, "IsWindowState", das::SideEffects::modifyExternal, "IsWindowState");
das::addExtern<DAS_BIND_FUN(SetWindowState)>(*this, lib, "SetWindowState", das::SideEffects::modifyExternal, "SetWindowState");
das::addExtern<DAS_BIND_FUN(ClearWindowState)>(*this, lib, "ClearWindowState", das::SideEffects::modifyExternal, "ClearWindowState");
das::addExtern<DAS_BIND_FUN(ToggleFullscreen)>(*this, lib, "ToggleFullscreen", das::SideEffects::modifyExternal, "ToggleFullscreen");
das::addExtern<DAS_BIND_FUN(ToggleBorderlessWindowed)>(*this, lib, "ToggleBorderlessWindowed", das::SideEffects::modifyExternal, "ToggleBorderlessWindowed");
das::addExtern<DAS_BIND_FUN(MaximizeWindow)>(*this, lib, "MaximizeWindow", das::SideEffects::modifyExternal, "MaximizeWindow");
das::addExtern<DAS_BIND_FUN(MinimizeWindow)>(*this, lib, "MinimizeWindow", das::SideEffects::modifyExternal, "MinimizeWindow");
das::addExtern<DAS_BIND_FUN(RestoreWindow)>(*this, lib, "RestoreWindow", das::SideEffects::modifyExternal, "RestoreWindow");
das::addExtern<DAS_BIND_FUN(SetWindowTitle)>(*this, lib, "SetWindowTitle", das::SideEffects::modifyExternal, "SetWindowTitle");
das::addExtern<DAS_BIND_FUN(SetWindowPosition)>(*this, lib, "SetWindowPosition", das::SideEffects::modifyExternal, "SetWindowPosition");
das::addExtern<DAS_BIND_FUN(SetWindowMonitor)>(*this, lib, "SetWindowMonitor", das::SideEffects::modifyExternal, "SetWindowMonitor");
das::addExtern<DAS_BIND_FUN(SetWindowMinSize)>(*this, lib, "SetWindowMinSize", das::SideEffects::modifyExternal, "SetWindowMinSize");
das::addExtern<DAS_BIND_FUN(SetWindowMaxSize)>(*this, lib, "SetWindowMaxSize", das::SideEffects::modifyExternal, "SetWindowMaxSize");
das::addExtern<DAS_BIND_FUN(SetWindowSize)>(*this, lib, "SetWindowSize", das::SideEffects::modifyExternal, "SetWindowSize");
das::addExtern<DAS_BIND_FUN(SetWindowOpacity)>(*this, lib, "SetWindowOpacity", das::SideEffects::modifyExternal, "SetWindowOpacity");
das::addExtern<DAS_BIND_FUN(SetWindowFocused)>(*this, lib, "SetWindowFocused", das::SideEffects::modifyExternal, "SetWindowFocused");
das::addExtern<DAS_BIND_FUN(GetScreenWidth)>(*this, lib, "GetScreenWidth", das::SideEffects::modifyExternal, "GetScreenWidth");
das::addExtern<DAS_BIND_FUN(GetScreenHeight)>(*this, lib, "GetScreenHeight", das::SideEffects::modifyExternal, "GetScreenHeight");
das::addExtern<DAS_BIND_FUN(GetRenderWidth)>(*this, lib, "GetRenderWidth", das::SideEffects::modifyExternal, "GetRenderWidth");
das::addExtern<DAS_BIND_FUN(GetRenderHeight)>(*this, lib, "GetRenderHeight", das::SideEffects::modifyExternal, "GetRenderHeight");
das::addExtern<DAS_BIND_FUN(GetMonitorCount)>(*this, lib, "GetMonitorCount", das::SideEffects::modifyExternal, "GetMonitorCount");
das::addExtern<DAS_BIND_FUN(GetCurrentMonitor)>(*this, lib, "GetCurrentMonitor", das::SideEffects::modifyExternal, "GetCurrentMonitor");
das::addExtern<DAS_BIND_FUN(GetMonitorWidth)>(*this, lib, "GetMonitorWidth", das::SideEffects::modifyExternal, "GetMonitorWidth");
das::addExtern<DAS_BIND_FUN(GetMonitorHeight)>(*this, lib, "GetMonitorHeight", das::SideEffects::modifyExternal, "GetMonitorHeight");
das::addExtern<DAS_BIND_FUN(GetMonitorPhysicalWidth)>(*this, lib, "GetMonitorPhysicalWidth", das::SideEffects::modifyExternal, "GetMonitorPhysicalWidth");
das::addExtern<DAS_BIND_FUN(GetMonitorPhysicalHeight)>(*this, lib, "GetMonitorPhysicalHeight", das::SideEffects::modifyExternal, "GetMonitorPhysicalHeight");
das::addExtern<DAS_BIND_FUN(GetMonitorRefreshRate)>(*this, lib, "GetMonitorRefreshRate", das::SideEffects::modifyExternal, "GetMonitorRefreshRate");
das::addExtern<DAS_BIND_FUN(SetClipboardText)>(*this, lib, "SetClipboardText", das::SideEffects::modifyExternal, "SetClipboardText");
das::addExtern<DAS_BIND_FUN(EnableEventWaiting)>(*this, lib, "EnableEventWaiting", das::SideEffects::modifyExternal, "EnableEventWaiting");
das::addExtern<DAS_BIND_FUN(DisableEventWaiting)>(*this, lib, "DisableEventWaiting", das::SideEffects::modifyExternal, "DisableEventWaiting");
das::addExtern<DAS_BIND_FUN(ShowCursor)>(*this, lib, "ShowCursor", das::SideEffects::modifyExternal, "ShowCursor");
das::addExtern<DAS_BIND_FUN(HideCursor)>(*this, lib, "HideCursor", das::SideEffects::modifyExternal, "HideCursor");
das::addExtern<DAS_BIND_FUN(IsCursorHidden)>(*this, lib, "IsCursorHidden", das::SideEffects::modifyExternal, "IsCursorHidden");
das::addExtern<DAS_BIND_FUN(EnableCursor)>(*this, lib, "EnableCursor", das::SideEffects::modifyExternal, "EnableCursor");
das::addExtern<DAS_BIND_FUN(DisableCursor)>(*this, lib, "DisableCursor", das::SideEffects::modifyExternal, "DisableCursor");
das::addExtern<DAS_BIND_FUN(IsCursorOnScreen)>(*this, lib, "IsCursorOnScreen", das::SideEffects::modifyExternal, "IsCursorOnScreen");
das::addExtern<DAS_BIND_FUN(BeginDrawing)>(*this, lib, "BeginDrawing", das::SideEffects::modifyExternal, "BeginDrawing");
das::addExtern<DAS_BIND_FUN(EndDrawing)>(*this, lib, "EndDrawing", das::SideEffects::modifyExternal, "EndDrawing");
das::addExtern<DAS_BIND_FUN(EndMode2D)>(*this, lib, "EndMode2D", das::SideEffects::modifyExternal, "EndMode2D");
das::addExtern<DAS_BIND_FUN(EndMode3D)>(*this, lib, "EndMode3D", das::SideEffects::modifyExternal, "EndMode3D");
das::addExtern<DAS_BIND_FUN(EndTextureMode)>(*this, lib, "EndTextureMode", das::SideEffects::modifyExternal, "EndTextureMode");
das::addExtern<DAS_BIND_FUN(EndShaderMode)>(*this, lib, "EndShaderMode", das::SideEffects::modifyExternal, "EndShaderMode");
das::addExtern<DAS_BIND_FUN(BeginBlendMode)>(*this, lib, "BeginBlendMode", das::SideEffects::modifyExternal, "BeginBlendMode");
das::addExtern<DAS_BIND_FUN(EndBlendMode)>(*this, lib, "EndBlendMode", das::SideEffects::modifyExternal, "EndBlendMode");
das::addExtern<DAS_BIND_FUN(BeginScissorMode)>(*this, lib, "BeginScissorMode", das::SideEffects::modifyExternal, "BeginScissorMode");
das::addExtern<DAS_BIND_FUN(EndScissorMode)>(*this, lib, "EndScissorMode", das::SideEffects::modifyExternal, "EndScissorMode");
das::addExtern<DAS_BIND_FUN(EndVrStereoMode)>(*this, lib, "EndVrStereoMode", das::SideEffects::modifyExternal, "EndVrStereoMode");
das::addExtern<DAS_BIND_FUN(SetTargetFPS)>(*this, lib, "SetTargetFPS", das::SideEffects::modifyExternal, "SetTargetFPS");
das::addExtern<DAS_BIND_FUN(GetFrameTime)>(*this, lib, "GetFrameTime", das::SideEffects::modifyExternal, "GetFrameTime");
das::addExtern<DAS_BIND_FUN(GetTime)>(*this, lib, "GetTime", das::SideEffects::modifyExternal, "GetTime");
das::addExtern<DAS_BIND_FUN(GetFPS)>(*this, lib, "GetFPS", das::SideEffects::modifyExternal, "GetFPS");
das::addExtern<DAS_BIND_FUN(SwapScreenBuffer)>(*this, lib, "SwapScreenBuffer", das::SideEffects::modifyExternal, "SwapScreenBuffer");
das::addExtern<DAS_BIND_FUN(PollInputEvents)>(*this, lib, "PollInputEvents", das::SideEffects::modifyExternal, "PollInputEvents");
das::addExtern<DAS_BIND_FUN(WaitTime)>(*this, lib, "WaitTime", das::SideEffects::modifyExternal, "WaitTime");
das::addExtern<DAS_BIND_FUN(SetRandomSeed)>(*this, lib, "SetRandomSeed", das::SideEffects::modifyExternal, "SetRandomSeed");
das::addExtern<DAS_BIND_FUN(GetRandomValue)>(*this, lib, "GetRandomValue", das::SideEffects::modifyExternal, "GetRandomValue");
das::addExtern<DAS_BIND_FUN(TakeScreenshot)>(*this, lib, "TakeScreenshot", das::SideEffects::modifyExternal, "TakeScreenshot");
das::addExtern<DAS_BIND_FUN(SetConfigFlags)>(*this, lib, "SetConfigFlags", das::SideEffects::modifyExternal, "SetConfigFlags");
das::addExtern<DAS_BIND_FUN(OpenURL)>(*this, lib, "OpenURL", das::SideEffects::modifyExternal, "OpenURL");
das::addExtern<DAS_BIND_FUN(SetTraceLogLevel)>(*this, lib, "SetTraceLogLevel", das::SideEffects::modifyExternal, "SetTraceLogLevel");
das::addExtern<DAS_BIND_FUN(LoadFileText)>(*this, lib, "LoadFileText", das::SideEffects::modifyExternal, "LoadFileText");
das::addExtern<DAS_BIND_FUN(UnloadFileText)>(*this, lib, "UnloadFileText", das::SideEffects::modifyExternal, "UnloadFileText");
das::addExtern<DAS_BIND_FUN(SaveFileText)>(*this, lib, "SaveFileText", das::SideEffects::modifyExternal, "SaveFileText");
das::addExtern<DAS_BIND_FUN(FileRename)>(*this, lib, "FileRename", das::SideEffects::modifyExternal, "FileRename");
das::addExtern<DAS_BIND_FUN(FileRemove)>(*this, lib, "FileRemove", das::SideEffects::modifyExternal, "FileRemove");
das::addExtern<DAS_BIND_FUN(FileCopy)>(*this, lib, "FileCopy", das::SideEffects::modifyExternal, "FileCopy");
das::addExtern<DAS_BIND_FUN(FileMove)>(*this, lib, "FileMove", das::SideEffects::modifyExternal, "FileMove");
das::addExtern<DAS_BIND_FUN(FileTextReplace)>(*this, lib, "FileTextReplace", das::SideEffects::modifyExternal, "FileTextReplace");
das::addExtern<DAS_BIND_FUN(FileTextFindIndex)>(*this, lib, "FileTextFindIndex", das::SideEffects::modifyExternal, "FileTextFindIndex");
das::addExtern<DAS_BIND_FUN(FileExists)>(*this, lib, "FileExists", das::SideEffects::modifyExternal, "FileExists");
das::addExtern<DAS_BIND_FUN(DirectoryExists)>(*this, lib, "DirectoryExists", das::SideEffects::modifyExternal, "DirectoryExists");
das::addExtern<DAS_BIND_FUN(IsFileExtension)>(*this, lib, "IsFileExtension", das::SideEffects::modifyExternal, "IsFileExtension");
das::addExtern<DAS_BIND_FUN(GetFileLength)>(*this, lib, "GetFileLength", das::SideEffects::modifyExternal, "GetFileLength");
das::addExtern<DAS_BIND_FUN(GetFileModTime)>(*this, lib, "GetFileModTime", das::SideEffects::modifyExternal, "GetFileModTime");
das::addExtern<DAS_BIND_FUN(MakeDirectory)>(*this, lib, "MakeDirectory", das::SideEffects::modifyExternal, "MakeDirectory");
das::addExtern<DAS_BIND_FUN(ChangeDirectory)>(*this, lib, "ChangeDirectory", das::SideEffects::modifyExternal, "ChangeDirectory");
das::addExtern<DAS_BIND_FUN(IsPathFile)>(*this, lib, "IsPathFile", das::SideEffects::modifyExternal, "IsPathFile");
das::addExtern<DAS_BIND_FUN(IsFileNameValid)>(*this, lib, "IsFileNameValid", das::SideEffects::modifyExternal, "IsFileNameValid");
das::addExtern<DAS_BIND_FUN(IsFileDropped)>(*this, lib, "IsFileDropped", das::SideEffects::modifyExternal, "IsFileDropped");
das::addExtern<DAS_BIND_FUN(LoadDroppedFiles), das::SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "LoadDroppedFiles", das::SideEffects::modifyExternal, "LoadDroppedFiles");
das::addExtern<DAS_BIND_FUN(GetDirectoryFileCount)>(*this, lib, "GetDirectoryFileCount", das::SideEffects::modifyExternal, "GetDirectoryFileCount");
das::addExtern<DAS_BIND_FUN(GetDirectoryFileCountEx)>(*this, lib, "GetDirectoryFileCountEx", das::SideEffects::modifyExternal, "GetDirectoryFileCountEx");
das::addExtern<DAS_BIND_FUN(IsKeyPressed)>(*this, lib, "IsKeyPressed", das::SideEffects::modifyExternal, "IsKeyPressed");
das::addExtern<DAS_BIND_FUN(IsKeyPressedRepeat)>(*this, lib, "IsKeyPressedRepeat", das::SideEffects::modifyExternal, "IsKeyPressedRepeat");
das::addExtern<DAS_BIND_FUN(IsKeyDown)>(*this, lib, "IsKeyDown", das::SideEffects::modifyExternal, "IsKeyDown");
das::addExtern<DAS_BIND_FUN(IsKeyReleased)>(*this, lib, "IsKeyReleased", das::SideEffects::modifyExternal, "IsKeyReleased");
das::addExtern<DAS_BIND_FUN(IsKeyUp)>(*this, lib, "IsKeyUp", das::SideEffects::modifyExternal, "IsKeyUp");
das::addExtern<DAS_BIND_FUN(GetKeyPressed)>(*this, lib, "GetKeyPressed", das::SideEffects::modifyExternal, "GetKeyPressed");
das::addExtern<DAS_BIND_FUN(GetCharPressed)>(*this, lib, "GetCharPressed", das::SideEffects::modifyExternal, "GetCharPressed");
das::addExtern<DAS_BIND_FUN(SetExitKey)>(*this, lib, "SetExitKey", das::SideEffects::modifyExternal, "SetExitKey");
das::addExtern<DAS_BIND_FUN(IsGamepadAvailable)>(*this, lib, "IsGamepadAvailable", das::SideEffects::modifyExternal, "IsGamepadAvailable");
das::addExtern<DAS_BIND_FUN(IsGamepadButtonPressed)>(*this, lib, "IsGamepadButtonPressed", das::SideEffects::modifyExternal, "IsGamepadButtonPressed");
das::addExtern<DAS_BIND_FUN(IsGamepadButtonDown)>(*this, lib, "IsGamepadButtonDown", das::SideEffects::modifyExternal, "IsGamepadButtonDown");
das::addExtern<DAS_BIND_FUN(IsGamepadButtonReleased)>(*this, lib, "IsGamepadButtonReleased", das::SideEffects::modifyExternal, "IsGamepadButtonReleased");
das::addExtern<DAS_BIND_FUN(IsGamepadButtonUp)>(*this, lib, "IsGamepadButtonUp", das::SideEffects::modifyExternal, "IsGamepadButtonUp");
das::addExtern<DAS_BIND_FUN(GetGamepadButtonPressed)>(*this, lib, "GetGamepadButtonPressed", das::SideEffects::modifyExternal, "GetGamepadButtonPressed");
das::addExtern<DAS_BIND_FUN(GetGamepadAxisCount)>(*this, lib, "GetGamepadAxisCount", das::SideEffects::modifyExternal, "GetGamepadAxisCount");
das::addExtern<DAS_BIND_FUN(GetGamepadAxisMovement)>(*this, lib, "GetGamepadAxisMovement", das::SideEffects::modifyExternal, "GetGamepadAxisMovement");
das::addExtern<DAS_BIND_FUN(SetGamepadMappings)>(*this, lib, "SetGamepadMappings", das::SideEffects::modifyExternal, "SetGamepadMappings");
das::addExtern<DAS_BIND_FUN(SetGamepadVibration)>(*this, lib, "SetGamepadVibration", das::SideEffects::modifyExternal, "SetGamepadVibration");
das::addExtern<DAS_BIND_FUN(IsMouseButtonPressed)>(*this, lib, "IsMouseButtonPressed", das::SideEffects::modifyExternal, "IsMouseButtonPressed");
das::addExtern<DAS_BIND_FUN(IsMouseButtonDown)>(*this, lib, "IsMouseButtonDown", das::SideEffects::modifyExternal, "IsMouseButtonDown");
das::addExtern<DAS_BIND_FUN(IsMouseButtonReleased)>(*this, lib, "IsMouseButtonReleased", das::SideEffects::modifyExternal, "IsMouseButtonReleased");
das::addExtern<DAS_BIND_FUN(IsMouseButtonUp)>(*this, lib, "IsMouseButtonUp", das::SideEffects::modifyExternal, "IsMouseButtonUp");
das::addExtern<DAS_BIND_FUN(GetMouseX)>(*this, lib, "GetMouseX", das::SideEffects::modifyExternal, "GetMouseX");
das::addExtern<DAS_BIND_FUN(GetMouseY)>(*this, lib, "GetMouseY", das::SideEffects::modifyExternal, "GetMouseY");
das::addExtern<DAS_BIND_FUN(SetMousePosition)>(*this, lib, "SetMousePosition", das::SideEffects::modifyExternal, "SetMousePosition");
das::addExtern<DAS_BIND_FUN(SetMouseOffset)>(*this, lib, "SetMouseOffset", das::SideEffects::modifyExternal, "SetMouseOffset");
das::addExtern<DAS_BIND_FUN(SetMouseScale)>(*this, lib, "SetMouseScale", das::SideEffects::modifyExternal, "SetMouseScale");
das::addExtern<DAS_BIND_FUN(GetMouseWheelMove)>(*this, lib, "GetMouseWheelMove", das::SideEffects::modifyExternal, "GetMouseWheelMove");
das::addExtern<DAS_BIND_FUN(SetMouseCursor)>(*this, lib, "SetMouseCursor", das::SideEffects::modifyExternal, "SetMouseCursor");
das::addExtern<DAS_BIND_FUN(GetTouchX)>(*this, lib, "GetTouchX", das::SideEffects::modifyExternal, "GetTouchX");
das::addExtern<DAS_BIND_FUN(GetTouchY)>(*this, lib, "GetTouchY", das::SideEffects::modifyExternal, "GetTouchY");
das::addExtern<DAS_BIND_FUN(GetTouchPointId)>(*this, lib, "GetTouchPointId", das::SideEffects::modifyExternal, "GetTouchPointId");
das::addExtern<DAS_BIND_FUN(GetTouchPointCount)>(*this, lib, "GetTouchPointCount", das::SideEffects::modifyExternal, "GetTouchPointCount");
das::addExtern<DAS_BIND_FUN(SetGesturesEnabled)>(*this, lib, "SetGesturesEnabled", das::SideEffects::modifyExternal, "SetGesturesEnabled");
das::addExtern<DAS_BIND_FUN(IsGestureDetected)>(*this, lib, "IsGestureDetected", das::SideEffects::modifyExternal, "IsGestureDetected");
das::addExtern<DAS_BIND_FUN(GetGestureDetected)>(*this, lib, "GetGestureDetected", das::SideEffects::modifyExternal, "GetGestureDetected");
das::addExtern<DAS_BIND_FUN(GetGestureHoldDuration)>(*this, lib, "GetGestureHoldDuration", das::SideEffects::modifyExternal, "GetGestureHoldDuration");
das::addExtern<DAS_BIND_FUN(GetGestureDragAngle)>(*this, lib, "GetGestureDragAngle", das::SideEffects::modifyExternal, "GetGestureDragAngle");
das::addExtern<DAS_BIND_FUN(GetGesturePinchAngle)>(*this, lib, "GetGesturePinchAngle", das::SideEffects::modifyExternal, "GetGesturePinchAngle");
das::addExtern<DAS_BIND_FUN(UpdateCamera)>(*this, lib, "UpdateCamera", das::SideEffects::modifyExternal, "UpdateCamera");
das::addExtern<DAS_BIND_FUN(ImageFormat)>(*this, lib, "ImageFormat", das::SideEffects::modifyExternal, "ImageFormat");
das::addExtern<DAS_BIND_FUN(ImageAlphaCrop)>(*this, lib, "ImageAlphaCrop", das::SideEffects::modifyExternal, "ImageAlphaCrop");
das::addExtern<DAS_BIND_FUN(ImageAlphaPremultiply)>(*this, lib, "ImageAlphaPremultiply", das::SideEffects::modifyExternal, "ImageAlphaPremultiply");
das::addExtern<DAS_BIND_FUN(ImageBlurGaussian)>(*this, lib, "ImageBlurGaussian", das::SideEffects::modifyExternal, "ImageBlurGaussian");
das::addExtern<DAS_BIND_FUN(ImageResize)>(*this, lib, "ImageResize", das::SideEffects::modifyExternal, "ImageResize");
das::addExtern<DAS_BIND_FUN(ImageResizeNN)>(*this, lib, "ImageResizeNN", das::SideEffects::modifyExternal, "ImageResizeNN");
das::addExtern<DAS_BIND_FUN(ImageMipmaps)>(*this, lib, "ImageMipmaps", das::SideEffects::modifyExternal, "ImageMipmaps");
das::addExtern<DAS_BIND_FUN(ImageDither)>(*this, lib, "ImageDither", das::SideEffects::modifyExternal, "ImageDither");
das::addExtern<DAS_BIND_FUN(ImageFlipVertical)>(*this, lib, "ImageFlipVertical", das::SideEffects::modifyExternal, "ImageFlipVertical");
das::addExtern<DAS_BIND_FUN(ImageFlipHorizontal)>(*this, lib, "ImageFlipHorizontal", das::SideEffects::modifyExternal, "ImageFlipHorizontal");
das::addExtern<DAS_BIND_FUN(ImageRotate)>(*this, lib, "ImageRotate", das::SideEffects::modifyExternal, "ImageRotate");
das::addExtern<DAS_BIND_FUN(ImageRotateCW)>(*this, lib, "ImageRotateCW", das::SideEffects::modifyExternal, "ImageRotateCW");
das::addExtern<DAS_BIND_FUN(ImageRotateCCW)>(*this, lib, "ImageRotateCCW", das::SideEffects::modifyExternal, "ImageRotateCCW");
das::addExtern<DAS_BIND_FUN(ImageColorInvert)>(*this, lib, "ImageColorInvert", das::SideEffects::modifyExternal, "ImageColorInvert");
das::addExtern<DAS_BIND_FUN(UnloadImageColors)>(*this, lib, "UnloadImageColors", das::SideEffects::modifyExternal, "UnloadImageColors");
das::addExtern<DAS_BIND_FUN(UnloadImagePalette)>(*this, lib, "UnloadImagePalette", das::SideEffects::modifyExternal, "UnloadImagePalette");
das::addExtern<DAS_BIND_FUN(GenTextureMipmaps)>(*this, lib, "GenTextureMipmaps", das::SideEffects::modifyExternal, "GenTextureMipmaps");
das::addExtern<DAS_BIND_FUN(GetPixelDataSize)>(*this, lib, "GetPixelDataSize", das::SideEffects::modifyExternal, "GetPixelDataSize");
das::addExtern<DAS_BIND_FUN(DrawFPS)>(*this, lib, "DrawFPS", das::SideEffects::modifyExternal, "DrawFPS");
das::addExtern<DAS_BIND_FUN(SetTextLineSpacing)>(*this, lib, "SetTextLineSpacing", das::SideEffects::modifyExternal, "SetTextLineSpacing");
das::addExtern<DAS_BIND_FUN(UnloadUTF8)>(*this, lib, "UnloadUTF8", das::SideEffects::modifyExternal, "UnloadUTF8");
das::addExtern<DAS_BIND_FUN(TextCopy)>(*this, lib, "TextCopy", das::SideEffects::modifyExternal, "TextCopy");
das::addExtern<DAS_BIND_FUN(TextIsEqual)>(*this, lib, "TextIsEqual", das::SideEffects::modifyExternal, "TextIsEqual");
das::addExtern<DAS_BIND_FUN(TextLength)>(*this, lib, "TextLength", das::SideEffects::modifyExternal, "TextLength");
das::addExtern<DAS_BIND_FUN(GetTextBetween)>(*this, lib, "GetTextBetween", das::SideEffects::modifyExternal, "GetTextBetween");
das::addExtern<DAS_BIND_FUN(TextReplace)>(*this, lib, "TextReplace", das::SideEffects::modifyExternal, "TextReplace");
das::addExtern<DAS_BIND_FUN(TextReplaceAlloc)>(*this, lib, "TextReplaceAlloc", das::SideEffects::modifyExternal, "TextReplaceAlloc");
das::addExtern<DAS_BIND_FUN(TextReplaceBetween)>(*this, lib, "TextReplaceBetween", das::SideEffects::modifyExternal, "TextReplaceBetween");
das::addExtern<DAS_BIND_FUN(TextReplaceBetweenAlloc)>(*this, lib, "TextReplaceBetweenAlloc", das::SideEffects::modifyExternal, "TextReplaceBetweenAlloc");
das::addExtern<DAS_BIND_FUN(TextInsert)>(*this, lib, "TextInsert", das::SideEffects::modifyExternal, "TextInsert");
das::addExtern<DAS_BIND_FUN(TextInsertAlloc)>(*this, lib, "TextInsertAlloc", das::SideEffects::modifyExternal, "TextInsertAlloc");
das::addExtern<DAS_BIND_FUN(TextToUpper)>(*this, lib, "TextToUpper", das::SideEffects::modifyExternal, "TextToUpper");
das::addExtern<DAS_BIND_FUN(TextToLower)>(*this, lib, "TextToLower", das::SideEffects::modifyExternal, "TextToLower");
das::addExtern<DAS_BIND_FUN(TextToPascal)>(*this, lib, "TextToPascal", das::SideEffects::modifyExternal, "TextToPascal");
das::addExtern<DAS_BIND_FUN(TextToSnake)>(*this, lib, "TextToSnake", das::SideEffects::modifyExternal, "TextToSnake");
das::addExtern<DAS_BIND_FUN(TextToCamel)>(*this, lib, "TextToCamel", das::SideEffects::modifyExternal, "TextToCamel");
das::addExtern<DAS_BIND_FUN(TextToInteger)>(*this, lib, "TextToInteger", das::SideEffects::modifyExternal, "TextToInteger");
das::addExtern<DAS_BIND_FUN(TextToFloat)>(*this, lib, "TextToFloat", das::SideEffects::modifyExternal, "TextToFloat");
das::addExtern<DAS_BIND_FUN(GenMeshTangents)>(*this, lib, "GenMeshTangents", das::SideEffects::modifyExternal, "GenMeshTangents");
das::addExtern<DAS_BIND_FUN(UnloadModelAnimations)>(*this, lib, "UnloadModelAnimations", das::SideEffects::modifyExternal, "UnloadModelAnimations");
das::addExtern<DAS_BIND_FUN(InitAudioDevice)>(*this, lib, "InitAudioDevice", das::SideEffects::modifyExternal, "InitAudioDevice");
das::addExtern<DAS_BIND_FUN(CloseAudioDevice)>(*this, lib, "CloseAudioDevice", das::SideEffects::modifyExternal, "CloseAudioDevice");
das::addExtern<DAS_BIND_FUN(IsAudioDeviceReady)>(*this, lib, "IsAudioDeviceReady", das::SideEffects::modifyExternal, "IsAudioDeviceReady");
das::addExtern<DAS_BIND_FUN(SetMasterVolume)>(*this, lib, "SetMasterVolume", das::SideEffects::modifyExternal, "SetMasterVolume");
das::addExtern<DAS_BIND_FUN(GetMasterVolume)>(*this, lib, "GetMasterVolume", das::SideEffects::modifyExternal, "GetMasterVolume");
das::addExtern<DAS_BIND_FUN(WaveCrop)>(*this, lib, "WaveCrop", das::SideEffects::modifyExternal, "WaveCrop");
das::addExtern<DAS_BIND_FUN(WaveFormat)>(*this, lib, "WaveFormat", das::SideEffects::modifyExternal, "WaveFormat");
das::addExtern<DAS_BIND_FUN(SetAudioStreamBufferSizeDefault)>(*this, lib, "SetAudioStreamBufferSizeDefault", das::SideEffects::modifyExternal, "SetAudioStreamBufferSizeDefault");

// --- Skipped functions (need manual wrappers) ---
// SKIP SetWindowIcon: struct-by-value param 'Image image' requires manual wrapper
// SKIP GetMonitorPosition: unsupported return type 'Vector2'
// SKIP GetWindowPosition: unsupported return type 'Vector2'
// SKIP GetWindowScaleDPI: unsupported return type 'Vector2'
// SKIP GetClipboardImage: unsupported return type 'Image'
// SKIP BeginVrStereoMode: struct-by-value param 'VrStereoConfig config' requires manual wrapper
// SKIP LoadVrStereoConfig: struct-by-value param 'VrDeviceInfo device' requires manual wrapper
// SKIP UnloadVrStereoConfig: struct-by-value param 'VrStereoConfig config' requires manual wrapper
// SKIP LoadShader: unsupported return type 'Shader'
// SKIP LoadShaderFromMemory: unsupported return type 'Shader'
// SKIP IsShaderValid: struct-by-value param 'Shader shader' requires manual wrapper
// SKIP GetShaderLocation: struct-by-value param 'Shader shader' requires manual wrapper
// SKIP GetShaderLocationAttrib: struct-by-value param 'Shader shader' requires manual wrapper
// SKIP SetShaderValueMatrix: struct-by-value param 'Shader shader' requires manual wrapper
// SKIP SetShaderValueTexture: struct-by-value param 'Shader shader' requires manual wrapper
// SKIP UnloadShader: struct-by-value param 'Shader shader' requires manual wrapper
// SKIP GetScreenToWorldRay: unsupported return type 'Ray'
// SKIP GetScreenToWorldRayEx: unsupported return type 'Ray'
// SKIP GetWorldToScreen: unsupported return type 'Vector2'
// SKIP GetWorldToScreenEx: unsupported return type 'Vector2'
// SKIP GetWorldToScreen2D: unsupported return type 'Vector2'
// SKIP GetScreenToWorld2D: unsupported return type 'Vector2'
// SKIP GetCameraMatrix: unsupported return type 'Matrix'
// SKIP GetCameraMatrix2D: unsupported return type 'Matrix'
// SKIP LoadRandomSequence: unsupported return type 'int *'
// SKIP UnloadRandomSequence: unsupported param 'int * sequence'
// SKIP MemAlloc: unsupported return type 'void *'
// SKIP MemRealloc: unsupported return type 'void *'
// SKIP MemFree: unsupported param 'void * ptr'
// SKIP UnloadFileData: unsupported param 'unsigned char * data'
// SKIP UnloadDirectoryFiles: struct-by-value param 'FilePathList files' requires manual wrapper
// SKIP UnloadDroppedFiles: struct-by-value param 'FilePathList files' requires manual wrapper
// SKIP ComputeCRC32: unsupported param 'unsigned char * data'
// SKIP ComputeMD5: unsupported return type 'unsigned int *'
// SKIP ComputeSHA1: unsupported return type 'unsigned int *'
// SKIP ComputeSHA256: unsupported return type 'unsigned int *'
// SKIP GetMousePosition: unsupported return type 'Vector2'
// SKIP GetMouseDelta: unsupported return type 'Vector2'
// SKIP GetMouseWheelMoveV: unsupported return type 'Vector2'
// SKIP GetTouchPosition: unsupported return type 'Vector2'
// SKIP GetGestureDragVector: unsupported return type 'Vector2'
// SKIP GetGesturePinchVector: unsupported return type 'Vector2'
// SKIP UpdateCameraPro: struct-by-value param 'Vector3 movement' requires manual wrapper
// SKIP SetShapesTexture: struct-by-value param 'Texture2D texture' requires manual wrapper
// SKIP GetShapesTexture: unsupported return type 'Texture2D'
// SKIP GetShapesTextureRectangle: unsupported return type 'Rectangle'
// SKIP DrawPixelV: struct-by-value param 'Vector2 position' requires manual wrapper
// SKIP DrawLineV: struct-by-value param 'Vector2 startPos' requires manual wrapper
// SKIP DrawLineStrip: struct-by-value param 'Color color' requires manual wrapper
// SKIP DrawLineBezier: struct-by-value param 'Vector2 startPos' requires manual wrapper
// SKIP DrawLineDashed: struct-by-value param 'Vector2 startPos' requires manual wrapper
// SKIP DrawCircleSector: struct-by-value param 'Vector2 center' requires manual wrapper
// SKIP DrawCircleSectorLines: struct-by-value param 'Vector2 center' requires manual wrapper
// SKIP DrawEllipse: struct-by-value param 'Color color' requires manual wrapper
// SKIP DrawEllipseV: struct-by-value param 'Vector2 center' requires manual wrapper
// SKIP DrawEllipseLines: struct-by-value param 'Color color' requires manual wrapper
// SKIP DrawEllipseLinesV: struct-by-value param 'Vector2 center' requires manual wrapper
// SKIP DrawRing: struct-by-value param 'Vector2 center' requires manual wrapper
// SKIP DrawRingLines: struct-by-value param 'Vector2 center' requires manual wrapper
// SKIP DrawRectangleGradientEx: struct-by-value param 'Rectangle rec' requires manual wrapper
// SKIP DrawRectangleRoundedLinesEx: struct-by-value param 'Rectangle rec' requires manual wrapper
// SKIP DrawSplineLinear: struct-by-value param 'Color color' requires manual wrapper
// SKIP DrawSplineBasis: struct-by-value param 'Color color' requires manual wrapper
// SKIP DrawSplineCatmullRom: struct-by-value param 'Color color' requires manual wrapper
// SKIP DrawSplineBezierQuadratic: struct-by-value param 'Color color' requires manual wrapper
// SKIP DrawSplineBezierCubic: struct-by-value param 'Color color' requires manual wrapper
// SKIP DrawSplineSegmentLinear: struct-by-value param 'Vector2 p1' requires manual wrapper
// SKIP DrawSplineSegmentBasis: struct-by-value param 'Vector2 p1' requires manual wrapper
// SKIP DrawSplineSegmentCatmullRom: struct-by-value param 'Vector2 p1' requires manual wrapper
// SKIP DrawSplineSegmentBezierQuadratic: struct-by-value param 'Vector2 p1' requires manual wrapper
// SKIP DrawSplineSegmentBezierCubic: struct-by-value param 'Vector2 p1' requires manual wrapper
// SKIP GetSplinePointLinear: unsupported return type 'Vector2'
// SKIP GetSplinePointBasis: unsupported return type 'Vector2'
// SKIP GetSplinePointCatmullRom: unsupported return type 'Vector2'
// SKIP GetSplinePointBezierQuad: unsupported return type 'Vector2'
// SKIP GetSplinePointBezierCubic: unsupported return type 'Vector2'
// SKIP CheckCollisionRecs: struct-by-value param 'Rectangle rec1' requires manual wrapper
// SKIP CheckCollisionCircles: struct-by-value param 'Vector2 center1' requires manual wrapper
// SKIP CheckCollisionCircleRec: struct-by-value param 'Vector2 center' requires manual wrapper
// SKIP CheckCollisionCircleLine: struct-by-value param 'Vector2 center' requires manual wrapper
// SKIP CheckCollisionPointCircle: struct-by-value param 'Vector2 point' requires manual wrapper
// SKIP CheckCollisionPointTriangle: struct-by-value param 'Vector2 point' requires manual wrapper
// SKIP CheckCollisionPointLine: struct-by-value param 'Vector2 point' requires manual wrapper
// SKIP CheckCollisionPointPoly: struct-by-value param 'Vector2 point' requires manual wrapper
// SKIP CheckCollisionLines: struct-by-value param 'Vector2 startPos1' requires manual wrapper
// SKIP GetCollisionRec: unsupported return type 'Rectangle'
// SKIP LoadImage: unsupported return type 'Image'
// SKIP LoadImageRaw: unsupported return type 'Image'
// SKIP LoadImageAnim: unsupported return type 'Image'
// SKIP LoadImageFromTexture: unsupported return type 'Image'
// SKIP LoadImageFromScreen: unsupported return type 'Image'
// SKIP IsImageValid: struct-by-value param 'Image image' requires manual wrapper
// SKIP UnloadImage: struct-by-value param 'Image image' requires manual wrapper
// SKIP ExportImage: struct-by-value param 'Image image' requires manual wrapper
// SKIP ExportImageToMemory: unsupported return type 'unsigned char *'
// SKIP ExportImageAsCode: struct-by-value param 'Image image' requires manual wrapper
// SKIP GenImageColor: unsupported return type 'Image'
// SKIP GenImageGradientLinear: unsupported return type 'Image'
// SKIP GenImageGradientRadial: unsupported return type 'Image'
// SKIP GenImageGradientSquare: unsupported return type 'Image'
// SKIP GenImageChecked: unsupported return type 'Image'
// SKIP GenImageWhiteNoise: unsupported return type 'Image'
// SKIP GenImagePerlinNoise: unsupported return type 'Image'
// SKIP GenImageCellular: unsupported return type 'Image'
// SKIP GenImageText: unsupported return type 'Image'
// SKIP ImageCopy: unsupported return type 'Image'
// SKIP ImageFromImage: unsupported return type 'Image'
// SKIP ImageFromChannel: unsupported return type 'Image'
// SKIP ImageText: unsupported return type 'Image'
// SKIP ImageTextEx: unsupported return type 'Image'
// SKIP ImageToPOT: struct-by-value param 'Color fill' requires manual wrapper
// SKIP ImageCrop: struct-by-value param 'Rectangle crop' requires manual wrapper
// SKIP ImageAlphaClear: struct-by-value param 'Color color' requires manual wrapper
// SKIP ImageAlphaMask: struct-by-value param 'Image alphaMask' requires manual wrapper
// SKIP ImageResizeCanvas: struct-by-value param 'Color fill' requires manual wrapper
// SKIP ImageColorTint: struct-by-value param 'Color color' requires manual wrapper
// SKIP LoadImageColors: unsupported return type 'Color *'
// SKIP LoadImagePalette: unsupported return type 'Color *'
// SKIP ImageClearBackground: struct-by-value param 'Color color' requires manual wrapper
// SKIP ImageDrawPixel: struct-by-value param 'Color color' requires manual wrapper
// SKIP ImageDrawPixelV: struct-by-value param 'Vector2 position' requires manual wrapper
// SKIP ImageDrawLine: struct-by-value param 'Color color' requires manual wrapper
// SKIP ImageDrawLineV: struct-by-value param 'Vector2 start' requires manual wrapper
// SKIP ImageDrawLineEx: struct-by-value param 'Vector2 start' requires manual wrapper
// SKIP ImageDrawCircle: struct-by-value param 'Color color' requires manual wrapper
// SKIP ImageDrawCircleV: struct-by-value param 'Vector2 center' requires manual wrapper
// SKIP ImageDrawCircleLines: struct-by-value param 'Color color' requires manual wrapper
// SKIP ImageDrawCircleLinesV: struct-by-value param 'Vector2 center' requires manual wrapper
// SKIP ImageDrawRectangle: struct-by-value param 'Color color' requires manual wrapper
// SKIP ImageDrawRectangleV: struct-by-value param 'Vector2 position' requires manual wrapper
// SKIP ImageDrawRectangleRec: struct-by-value param 'Rectangle rec' requires manual wrapper
// SKIP ImageDrawRectangleLines: struct-by-value param 'Rectangle rec' requires manual wrapper
// SKIP ImageDrawTriangle: struct-by-value param 'Vector2 v1' requires manual wrapper
// SKIP ImageDrawTriangleEx: struct-by-value param 'Vector2 v1' requires manual wrapper
// SKIP ImageDrawTriangleLines: struct-by-value param 'Vector2 v1' requires manual wrapper
// SKIP ImageDrawTriangleFan: struct-by-value param 'Color color' requires manual wrapper
// SKIP ImageDrawTriangleStrip: struct-by-value param 'Color color' requires manual wrapper
// SKIP ImageDraw: struct-by-value param 'Image src' requires manual wrapper
// SKIP ImageDrawText: struct-by-value param 'Color color' requires manual wrapper
// SKIP ImageDrawTextEx: struct-by-value param 'Font font' requires manual wrapper
// SKIP LoadTexture: unsupported return type 'Texture2D'
// SKIP LoadTextureFromImage: unsupported return type 'Texture2D'
// SKIP LoadTextureCubemap: unsupported return type 'TextureCubemap'
// SKIP LoadRenderTexture: unsupported return type 'RenderTexture2D'
// SKIP IsTextureValid: struct-by-value param 'Texture2D texture' requires manual wrapper
// SKIP UnloadTexture: struct-by-value param 'Texture2D texture' requires manual wrapper
// SKIP IsRenderTextureValid: struct-by-value param 'RenderTexture2D target' requires manual wrapper
// SKIP UnloadRenderTexture: struct-by-value param 'RenderTexture2D target' requires manual wrapper
// SKIP SetTextureFilter: struct-by-value param 'Texture2D texture' requires manual wrapper
// SKIP SetTextureWrap: struct-by-value param 'Texture2D texture' requires manual wrapper
// SKIP DrawTexture: struct-by-value param 'Texture2D texture' requires manual wrapper
// SKIP DrawTextureV: struct-by-value param 'Texture2D texture' requires manual wrapper
// SKIP DrawTextureEx: struct-by-value param 'Texture2D texture' requires manual wrapper
// SKIP DrawTextureRec: struct-by-value param 'Texture2D texture' requires manual wrapper
// SKIP DrawTexturePro: struct-by-value param 'Texture2D texture' requires manual wrapper
// SKIP DrawTextureNPatch: struct-by-value param 'Texture2D texture' requires manual wrapper
// SKIP ColorIsEqual: struct-by-value param 'Color col1' requires manual wrapper
// SKIP Fade: unsupported return type 'Color'
// SKIP ColorToInt: struct-by-value param 'Color color' requires manual wrapper
// SKIP ColorNormalize: unsupported return type 'Vector4'
// SKIP ColorFromNormalized: unsupported return type 'Color'
// SKIP ColorToHSV: unsupported return type 'Vector3'
// SKIP ColorFromHSV: unsupported return type 'Color'
// SKIP ColorTint: unsupported return type 'Color'
// SKIP ColorBrightness: unsupported return type 'Color'
// SKIP ColorContrast: unsupported return type 'Color'
// SKIP ColorAlpha: unsupported return type 'Color'
// SKIP ColorAlphaBlend: unsupported return type 'Color'
// SKIP ColorLerp: unsupported return type 'Color'
// SKIP GetColor: unsupported return type 'Color'
// SKIP GetPixelColor: unsupported return type 'Color'
// SKIP SetPixelColor: unsupported param 'void * dstPtr'
// SKIP GetFontDefault: unsupported return type 'Font'
// SKIP LoadFont: unsupported return type 'Font'
// SKIP LoadFontFromImage: unsupported return type 'Font'
// SKIP IsFontValid: struct-by-value param 'Font font' requires manual wrapper
// SKIP UnloadFont: struct-by-value param 'Font font' requires manual wrapper
// SKIP ExportFontAsCode: struct-by-value param 'Font font' requires manual wrapper
// SKIP DrawTextPro: struct-by-value param 'Font font' requires manual wrapper
// SKIP MeasureTextCodepoints: unsupported return type 'Vector2'
// SKIP LoadUTF8: unsupported param 'const int * codepoints'
// SKIP UnloadTextLines: unsupported param 'char ** text'
// SKIP TextAppend: unsupported param 'int * position'
// SKIP DrawCapsule: struct-by-value param 'Vector3 startPos' requires manual wrapper
// SKIP DrawCapsuleWires: struct-by-value param 'Vector3 startPos' requires manual wrapper
// SKIP LoadModel: unsupported return type 'Model'
// SKIP LoadModelFromMesh: unsupported return type 'Model'
// SKIP IsModelValid: struct-by-value param 'Model model' requires manual wrapper
// SKIP UnloadModel: struct-by-value param 'Model model' requires manual wrapper
// SKIP GetModelBoundingBox: unsupported return type 'BoundingBox'
// SKIP UnloadMesh: struct-by-value param 'Mesh mesh' requires manual wrapper
// SKIP ExportMeshAsCode: struct-by-value param 'Mesh mesh' requires manual wrapper
// SKIP GenMeshPoly: unsupported return type 'Mesh'
// SKIP GenMeshPlane: unsupported return type 'Mesh'
// SKIP GenMeshCube: unsupported return type 'Mesh'
// SKIP GenMeshSphere: unsupported return type 'Mesh'
// SKIP GenMeshHemiSphere: unsupported return type 'Mesh'
// SKIP GenMeshCylinder: unsupported return type 'Mesh'
// SKIP GenMeshCone: unsupported return type 'Mesh'
// SKIP GenMeshTorus: unsupported return type 'Mesh'
// SKIP GenMeshKnot: unsupported return type 'Mesh'
// SKIP LoadMaterialDefault: unsupported return type 'Material'
// SKIP IsMaterialValid: struct-by-value param 'Material material' requires manual wrapper
// SKIP UnloadMaterial: struct-by-value param 'Material material' requires manual wrapper
// SKIP UpdateModelAnimation: struct-by-value param 'Model model' requires manual wrapper
// SKIP UpdateModelAnimationEx: struct-by-value param 'Model model' requires manual wrapper
// SKIP CheckCollisionSpheres: struct-by-value param 'Vector3 center1' requires manual wrapper
// SKIP CheckCollisionBoxes: struct-by-value param 'BoundingBox box1' requires manual wrapper
// SKIP CheckCollisionBoxSphere: struct-by-value param 'BoundingBox box' requires manual wrapper
// SKIP GetRayCollisionSphere: unsupported return type 'RayCollision'
// SKIP GetRayCollisionBox: unsupported return type 'RayCollision'
// SKIP GetRayCollisionMesh: unsupported return type 'RayCollision'
// SKIP GetRayCollisionTriangle: unsupported return type 'RayCollision'
// SKIP GetRayCollisionQuad: unsupported return type 'RayCollision'
// SKIP LoadWave: unsupported return type 'Wave'
// SKIP LoadWaveFromMemory: unsupported return type 'Wave'
// SKIP IsWaveValid: struct-by-value param 'Wave wave' requires manual wrapper
// SKIP LoadSound: unsupported return type 'Sound'
// SKIP LoadSoundFromWave: unsupported return type 'Sound'
// SKIP LoadSoundAlias: unsupported return type 'Sound'
// SKIP IsSoundValid: struct-by-value param 'Sound sound' requires manual wrapper
// SKIP UpdateSound: struct-by-value param 'Sound sound' requires manual wrapper
// SKIP UnloadWave: struct-by-value param 'Wave wave' requires manual wrapper
// SKIP UnloadSound: struct-by-value param 'Sound sound' requires manual wrapper
// SKIP UnloadSoundAlias: struct-by-value param 'Sound alias' requires manual wrapper
// SKIP ExportWave: struct-by-value param 'Wave wave' requires manual wrapper
// SKIP ExportWaveAsCode: struct-by-value param 'Wave wave' requires manual wrapper
// SKIP PlaySound: struct-by-value param 'Sound sound' requires manual wrapper
// SKIP StopSound: struct-by-value param 'Sound sound' requires manual wrapper
// SKIP PauseSound: struct-by-value param 'Sound sound' requires manual wrapper
// SKIP ResumeSound: struct-by-value param 'Sound sound' requires manual wrapper
// SKIP IsSoundPlaying: struct-by-value param 'Sound sound' requires manual wrapper
// SKIP SetSoundVolume: struct-by-value param 'Sound sound' requires manual wrapper
// SKIP SetSoundPitch: struct-by-value param 'Sound sound' requires manual wrapper
// SKIP SetSoundPan: struct-by-value param 'Sound sound' requires manual wrapper
// SKIP WaveCopy: unsupported return type 'Wave'
// SKIP LoadWaveSamples: unsupported return type 'float *'
// SKIP UnloadWaveSamples: unsupported param 'float * samples'
// SKIP LoadMusicStream: unsupported return type 'Music'
// SKIP LoadMusicStreamFromMemory: unsupported return type 'Music'
// SKIP IsMusicValid: struct-by-value param 'Music music' requires manual wrapper
// SKIP UnloadMusicStream: struct-by-value param 'Music music' requires manual wrapper
// SKIP PlayMusicStream: struct-by-value param 'Music music' requires manual wrapper
// SKIP IsMusicStreamPlaying: struct-by-value param 'Music music' requires manual wrapper
// SKIP UpdateMusicStream: struct-by-value param 'Music music' requires manual wrapper
// SKIP StopMusicStream: struct-by-value param 'Music music' requires manual wrapper
// SKIP PauseMusicStream: struct-by-value param 'Music music' requires manual wrapper
// SKIP ResumeMusicStream: struct-by-value param 'Music music' requires manual wrapper
// SKIP SeekMusicStream: struct-by-value param 'Music music' requires manual wrapper
// SKIP SetMusicVolume: struct-by-value param 'Music music' requires manual wrapper
// SKIP SetMusicPitch: struct-by-value param 'Music music' requires manual wrapper
// SKIP SetMusicPan: struct-by-value param 'Music music' requires manual wrapper
// SKIP GetMusicTimeLength: struct-by-value param 'Music music' requires manual wrapper
// SKIP GetMusicTimePlayed: struct-by-value param 'Music music' requires manual wrapper
// SKIP LoadAudioStream: unsupported return type 'AudioStream'
// SKIP IsAudioStreamValid: struct-by-value param 'AudioStream stream' requires manual wrapper
// SKIP UnloadAudioStream: struct-by-value param 'AudioStream stream' requires manual wrapper
// SKIP UpdateAudioStream: struct-by-value param 'AudioStream stream' requires manual wrapper
// SKIP IsAudioStreamProcessed: struct-by-value param 'AudioStream stream' requires manual wrapper
// SKIP PlayAudioStream: struct-by-value param 'AudioStream stream' requires manual wrapper
// SKIP PauseAudioStream: struct-by-value param 'AudioStream stream' requires manual wrapper
// SKIP ResumeAudioStream: struct-by-value param 'AudioStream stream' requires manual wrapper
// SKIP IsAudioStreamPlaying: struct-by-value param 'AudioStream stream' requires manual wrapper
// SKIP StopAudioStream: struct-by-value param 'AudioStream stream' requires manual wrapper
// SKIP SetAudioStreamVolume: struct-by-value param 'AudioStream stream' requires manual wrapper
// SKIP SetAudioStreamPitch: struct-by-value param 'AudioStream stream' requires manual wrapper
// SKIP SetAudioStreamPan: struct-by-value param 'AudioStream stream' requires manual wrapper

// --- String-returning wrappers ---
das::addExtern<DAS_BIND_FUN(raylib_wrap_GetMonitorName)>(*this, lib, "GetMonitorName", das::SideEffects::modifyExternal, "raylib_wrap_GetMonitorName");
das::addExtern<DAS_BIND_FUN(raylib_wrap_GetClipboardText)>(*this, lib, "GetClipboardText", das::SideEffects::modifyExternal, "raylib_wrap_GetClipboardText");
das::addExtern<DAS_BIND_FUN(raylib_wrap_GetFileExtension)>(*this, lib, "GetFileExtension", das::SideEffects::modifyExternal, "raylib_wrap_GetFileExtension");
das::addExtern<DAS_BIND_FUN(raylib_wrap_GetFileName)>(*this, lib, "GetFileName", das::SideEffects::modifyExternal, "raylib_wrap_GetFileName");
das::addExtern<DAS_BIND_FUN(raylib_wrap_GetFileNameWithoutExt)>(*this, lib, "GetFileNameWithoutExt", das::SideEffects::modifyExternal, "raylib_wrap_GetFileNameWithoutExt");
das::addExtern<DAS_BIND_FUN(raylib_wrap_GetDirectoryPath)>(*this, lib, "GetDirectoryPath", das::SideEffects::modifyExternal, "raylib_wrap_GetDirectoryPath");
das::addExtern<DAS_BIND_FUN(raylib_wrap_GetPrevDirectoryPath)>(*this, lib, "GetPrevDirectoryPath", das::SideEffects::modifyExternal, "raylib_wrap_GetPrevDirectoryPath");
das::addExtern<DAS_BIND_FUN(raylib_wrap_GetWorkingDirectory)>(*this, lib, "GetWorkingDirectory", das::SideEffects::modifyExternal, "raylib_wrap_GetWorkingDirectory");
das::addExtern<DAS_BIND_FUN(raylib_wrap_GetApplicationDirectory)>(*this, lib, "GetApplicationDirectory", das::SideEffects::modifyExternal, "raylib_wrap_GetApplicationDirectory");
das::addExtern<DAS_BIND_FUN(raylib_wrap_GetKeyName)>(*this, lib, "GetKeyName", das::SideEffects::modifyExternal, "raylib_wrap_GetKeyName");
das::addExtern<DAS_BIND_FUN(raylib_wrap_GetGamepadName)>(*this, lib, "GetGamepadName", das::SideEffects::modifyExternal, "raylib_wrap_GetGamepadName");
das::addExtern<DAS_BIND_FUN(raylib_wrap_TextSubtext)>(*this, lib, "TextSubtext", das::SideEffects::modifyExternal, "raylib_wrap_TextSubtext");
das::addExtern<DAS_BIND_FUN(raylib_wrap_TextRemoveSpaces)>(*this, lib, "TextRemoveSpaces", das::SideEffects::modifyExternal, "raylib_wrap_TextRemoveSpaces");
