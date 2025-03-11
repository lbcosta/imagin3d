#include <memory>
#include <valarray>

#include "raylib.h"
#include "lib/Math/vec3.h"
#include "lib/Math/mat4.h"
#include "lib/Sphere/Sphere.h"
#include "lib/Cylinder/Cylinder.h"
#include "lib/Cone/Cone.h"
#include "lib/Plane/Plane.h"
#include "lib/Cube/Cube.h"
#include "lib/Scene/Scene.h"

// Canvas
// 800x450 = 16:9
constexpr int CANVAS_WIDTH = 500; // pixels
constexpr int CANVAS_HEIGHT = 500; // pixels
constexpr int FPS = 1;

// Window/Frame
constexpr double WINDOW_WIDTH = 50;
constexpr double WINDOW_HEIGHT = 50;
constexpr int N_COL = 500;
constexpr int N_ROW = 500;

vec3 FIXED_ORIGIN = 0.0;

using namespace std;

int main() {
    InitWindow(CANVAS_WIDTH, CANVAS_HEIGHT, "Imagin3D");
    SetTargetFPS(FPS);

    vec3 woodTexture{0.54, 0.27, 0.07};

    vector<Object*> objects{
        new Plane( // Piso
            {0, -150, 0},
            {0, 1, 0},
            {woodTexture, woodTexture, woodTexture, 1}
            ),
        new Plane( // Parede Direita
            {200, -150, 0},
            {-1, 0, 0},
            {{0.686, 0.933, 0.933}, {0.686, 0.933, 0.933}, {0.686, 0.933, 0.933}, 1}
        ),
        new Plane( // Parede de trás
            {200, -150, -400},
            {0, 0, 1},
{{0.686, 0.933, 0.933}, {0.686, 0.933, 0.933}, {0.686, 0.933, 0.933}, 1}
        ),
        new Plane( // Parede Esquerda
            {-200, -150, 0},
            {1, 0, 0},
        {{0.686, 0.933, 0.933}, {0.686, 0.933, 0.933}, {0.686, 0.933, 0.933}, 1}
        ),
        new Plane( // Telhado
            {0, 150, 0},
            {0, -1, 0},
{{0.933, 0.933, 0.933}, {0.933, 0.933, 0.933}, {0.933, 0.933, 0.933}, 1}
        ),
//         new Cylinder(
//             {0, -150, -200},
//             5,
//             90,
//             {0, 1, 0},
// {{0.824, 0.706, 0.549}, {0.824, 0.706, 0.549}, {0.824, 0.706, 0.549}, 10}
//         ),
//         new Cone(
//             {0, -60, -200},
//             90,
//             150,
//             {0, 1, 0},
// {{0, 1, 0.498}, {0, 1, 0.498}, {0, 1, 0.498}, 10}
//          ),
    };

    vec3 sphereCenter = {0, 95, -200};
    auto *sphere = new Sphere(
        sphereCenter,
        5,
        {{0.854, 0.647, 0.125}, {0.854, 0.647, 0.125}, {0.854, 0.647, 0.125}, 10}
    );

    sphere
        ->Translate({50, -50, 100})
        ->Scale({5, 5, 5}, sphereCenter)
        ->Transform();

    objects.push_back(sphere);

    // vec3 cubeCenter = {0, -150, -165};
    vec3 cubeCenter = {0, -50, -165};
    double cubeSize = 40;
    auto *cube = new Cube(
            cubeCenter,
            cubeSize,
{{1, 0.078, 0.576}, {1, 0.078, 0.576}, {1, 0.078, 0.576}, 10}
    );

    cube
        ->Rotate(30, cubeCenter, cubeCenter + vec3{2, 0, 1})
        ->Transform();

    objects.push_back(cube);

    Scene scene(SceneParams{
        .CameraPosition = FIXED_ORIGIN,
        .LightPosition = {-100, 140, -20},
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