#include "raylib.h"
#include "lib/Math/vec3.h"
#include "lib/Sphere/Sphere.h"
#include "lib/Scene/Scene.h"

// Canvas
// 800x450 = 16:9
constexpr int CANVAS_WIDTH = 800; // pixels
constexpr int CANVAS_HEIGHT = 450; // pixels
constexpr int FPS = 15;

// Window/Frame
constexpr double WINDOW_WIDTH = 80.0f;
constexpr double WINDOW_HEIGHT = 45.0f;
constexpr int N_COL = 800;
constexpr int N_ROW = 450;

int main() {
    InitWindow(CANVAS_WIDTH, CANVAS_HEIGHT, "Imagin3D");
    SetTargetFPS(FPS);

    Scene scene({
        .CameraPosition =0.0,
        .WindowWidth = WINDOW_WIDTH,
        .WindowHeight = WINDOW_HEIGHT,
        .CanvasRowsNumber = N_ROW,
        .CanvasColsNumber = N_COL,
        .Objects = nullptr,
    });

    while (!WindowShouldClose()) {
        BeginDrawing();
        scene.Render(nullptr);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}