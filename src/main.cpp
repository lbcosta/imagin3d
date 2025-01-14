#include "raylib.h"

int main() {
    // 800x450 is 16:9
    InitWindow(800, 450, "Imagin3D");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(SKYBLUE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}