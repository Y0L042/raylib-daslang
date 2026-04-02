// GENERATED — do not edit manually.
// Regenerate with: python3 tools/gen_raylib_bindings.py

// Wrappers for functions returning const char* (daslang needs char* from heap)

// Wrapper: GetMonitorName -> returns das-managed string
static char *raylib_wrap_GetMonitorName(int monitor, das::Context *ctx) {
    const char *s = GetMonitorName(monitor);
    return s ? ctx->stringHeap->impl_allocateString(ctx, s, (uint32_t)strlen(s)) : nullptr;
}

// Wrapper: GetClipboardText -> returns das-managed string
static char *raylib_wrap_GetClipboardText(das::Context *ctx) {
    const char *s = GetClipboardText();
    return s ? ctx->stringHeap->impl_allocateString(ctx, s, (uint32_t)strlen(s)) : nullptr;
}

// Wrapper: GetFileExtension -> returns das-managed string
static char *raylib_wrap_GetFileExtension(const char *fileName, das::Context *ctx) {
    const char *s = GetFileExtension(fileName);
    return s ? ctx->stringHeap->impl_allocateString(ctx, s, (uint32_t)strlen(s)) : nullptr;
}

// Wrapper: GetFileName -> returns das-managed string
static char *raylib_wrap_GetFileName(const char *filePath, das::Context *ctx) {
    const char *s = GetFileName(filePath);
    return s ? ctx->stringHeap->impl_allocateString(ctx, s, (uint32_t)strlen(s)) : nullptr;
}

// Wrapper: GetFileNameWithoutExt -> returns das-managed string
static char *raylib_wrap_GetFileNameWithoutExt(const char *filePath, das::Context *ctx) {
    const char *s = GetFileNameWithoutExt(filePath);
    return s ? ctx->stringHeap->impl_allocateString(ctx, s, (uint32_t)strlen(s)) : nullptr;
}

// Wrapper: GetDirectoryPath -> returns das-managed string
static char *raylib_wrap_GetDirectoryPath(const char *filePath, das::Context *ctx) {
    const char *s = GetDirectoryPath(filePath);
    return s ? ctx->stringHeap->impl_allocateString(ctx, s, (uint32_t)strlen(s)) : nullptr;
}

// Wrapper: GetPrevDirectoryPath -> returns das-managed string
static char *raylib_wrap_GetPrevDirectoryPath(const char *dirPath, das::Context *ctx) {
    const char *s = GetPrevDirectoryPath(dirPath);
    return s ? ctx->stringHeap->impl_allocateString(ctx, s, (uint32_t)strlen(s)) : nullptr;
}

// Wrapper: GetWorkingDirectory -> returns das-managed string
static char *raylib_wrap_GetWorkingDirectory(das::Context *ctx) {
    const char *s = GetWorkingDirectory();
    return s ? ctx->stringHeap->impl_allocateString(ctx, s, (uint32_t)strlen(s)) : nullptr;
}

// Wrapper: GetApplicationDirectory -> returns das-managed string
static char *raylib_wrap_GetApplicationDirectory(das::Context *ctx) {
    const char *s = GetApplicationDirectory();
    return s ? ctx->stringHeap->impl_allocateString(ctx, s, (uint32_t)strlen(s)) : nullptr;
}

// Wrapper: GetKeyName -> returns das-managed string
static char *raylib_wrap_GetKeyName(int key, das::Context *ctx) {
    const char *s = GetKeyName(key);
    return s ? ctx->stringHeap->impl_allocateString(ctx, s, (uint32_t)strlen(s)) : nullptr;
}

// Wrapper: GetGamepadName -> returns das-managed string
static char *raylib_wrap_GetGamepadName(int gamepad, das::Context *ctx) {
    const char *s = GetGamepadName(gamepad);
    return s ? ctx->stringHeap->impl_allocateString(ctx, s, (uint32_t)strlen(s)) : nullptr;
}

// Wrapper: TextSubtext -> returns das-managed string
static char *raylib_wrap_TextSubtext(const char *text, int position, int length, das::Context *ctx) {
    const char *s = TextSubtext(text, position, length);
    return s ? ctx->stringHeap->impl_allocateString(ctx, s, (uint32_t)strlen(s)) : nullptr;
}

// Wrapper: TextRemoveSpaces -> returns das-managed string
static char *raylib_wrap_TextRemoveSpaces(const char *text, das::Context *ctx) {
    const char *s = TextRemoveSpaces(text);
    return s ? ctx->stringHeap->impl_allocateString(ctx, s, (uint32_t)strlen(s)) : nullptr;
}
