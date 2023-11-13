#include <raylib.h>

int main(void) {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Hello, raylib!");

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose()) {
        // Update
        // TODO: Update your game logic here

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello, raylib!", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }

    // De-initialization
    CloseWindow();

    return 0;
}
-------------------------------------------------