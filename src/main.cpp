#include "raylib.h"
#include "lib/Math/vec3.h"
#include "lib/Sphere/Sphere.h"

// Canvas
// 800x450 = 16:9
constexpr int CANVAS_WIDTH = 500; // pixels
constexpr int CANVAS_HEIGHT = 500; // pixels
constexpr int FPS = 15;
constexpr int N_COL = 500;
constexpr int N_ROW = 500;
constexpr double FIXED_Z = -30;
vec3 FIXED_ORIGIN = 0.0;

// Window/Frame
constexpr double WINDOW_WIDTH = 60.0f;
constexpr double WINDOW_HEIGHT = 60.0f;

int main() {
    InitWindow(CANVAS_WIDTH, CANVAS_HEIGHT, "Imagin3D");
    SetTargetFPS(FPS);

    double deltaY = WINDOW_HEIGHT / N_ROW;
    double deltaX = WINDOW_WIDTH / N_COL;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(GRAY);

        Color pixel;
        for (int row = 0; row <= N_ROW; row++) {
            for (int col = 0; col <= N_COL; col++) {
                vec3 p = {
                    (-WINDOW_WIDTH/2) + (deltaX/2) + (col * deltaX),
                    (WINDOW_HEIGHT/2) - (deltaY/2) - (row * deltaY),
                    FIXED_Z
                };

                VectorRay ray(FIXED_ORIGIN, p);
                ObjectMaterial sphereMaterial {vec3(), vec3(), vec3(), 0.0};

                if (Sphere sphere({0.0, 0.0, -100.0}, 40.0, sphereMaterial); sphere.RayIntersection(ray) < 0) {
                    pixel = SKYBLUE;
                } else {
                    pixel = RED;
                }

                DrawPixel(col, row, pixel);
            }
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}