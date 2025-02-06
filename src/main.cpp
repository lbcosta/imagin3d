#include <memory>

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
constexpr double WINDOW_WIDTH = 80;
constexpr double WINDOW_HEIGHT = 45;
constexpr int N_COL = 800;
constexpr int N_ROW = 450;

using namespace std;

int main() {
    InitWindow(CANVAS_WIDTH, CANVAS_HEIGHT, "Imagin3D");
    SetTargetFPS(FPS);

    vector<Object*> objects;

    objects.push_back(
        new Sphere({0.0, 0.0, -100.0}, 40.0, {vec3(), vec3(), vec3(), 0.0})
    );

    Scene scene(SceneParams{
        .CameraPosition = 0.0,
        .WindowWidth = WINDOW_WIDTH,
        .WindowHeight = WINDOW_HEIGHT,
        .CanvasRowsNumber = N_ROW,
        .CanvasColsNumber = N_COL,
        .Objects = objects,
    });

    while (!WindowShouldClose()) {
        BeginDrawing();
        scene.Render();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}