#include <memory>

#include "raylib.h"
#include "lib/Math/vec3.h"
#include "lib/Sphere/Sphere.h"
#include "lib/Plane/Plane.h"
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

vec3 FIXED_ORIGIN = 0.0;

using namespace std;

int main() {
    InitWindow(CANVAS_WIDTH, CANVAS_HEIGHT, "Imagin3D");
    SetTargetFPS(FPS);

    vector<Object*> objects{
        new Sphere(
            {0.0, 0.0, -100.0},
            40.0,
            {
                .AmbientReflection = vec3(0.7, 0.2, 0.2),
                .DiffuseReflection = vec3(0.7, 0.2, 0.2),
                .SpecularReflection = vec3(0.7, 0.2, 0.2),
                .Shininess = 10.0
            }
        ),
        new Plane( // Piso
            {0.0, -40.0, 0.0},
            {0.0, 1.0, 0.0},
            {
                .AmbientReflection = vec3(0.2, 0.7, 0.2),
                .DiffuseReflection = vec3(0.2, 0.7, 0.2),
                .SpecularReflection = vec3(0.0),
                .Shininess = 1.0
            }
            ),
        new Plane( // Parede
            {0.0, 0.0, -200.0},
            {0.0, 0.0, 1.0},
            {
                .AmbientReflection = vec3(0.3, 0.3, 0.7),
                .DiffuseReflection = vec3(0.3, 0.3, 0.7),
                .SpecularReflection = vec3(0.0),
                .Shininess = 1.0
            }
        )
    };

    Scene scene(SceneParams{
        .CameraPosition = FIXED_ORIGIN,
        .LightPosition = {0, 60, -30},
        .LightIntensity = {0.7, 0.7, 0.7},
        .AmbientLight = {0.3, 0.3, 0.3},
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