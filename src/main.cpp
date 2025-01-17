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

// Window/Frame
constexpr float WINDOW_WIDTH = 60.0f;
constexpr float WINDOW_HEIGHT = 60.0f;

int main() {
    InitWindow(CANVAS_WIDTH, CANVAS_HEIGHT, "Imagin3D");
    SetTargetFPS(FPS);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(GRAY);

        vec3 rayOrigin(0.0);
        float sphereRadius = 40.0;
        vec3 sphereCenter(0.0, 0.0, -100.0);

        float deltaY = WINDOW_HEIGHT / N_ROW;
        float deltaX = WINDOW_WIDTH / N_COL;
        Color pixel;

        for (int row = 0; row <= N_ROW; row++) {
            float y = (WINDOW_HEIGHT/2) - (deltaY/2) - (static_cast<float>(row) * deltaY);
            for (int col = 0; col <= N_COL; col++) {
                float x = (-WINDOW_WIDTH/2) + (deltaX/2) + (static_cast<float>(col) * deltaX);
                float z = -30.0;
                vec3 at = {x, y, z};

                VectorRay ray(rayOrigin, at);
                ObjectMaterial sphereMaterial {vec3(), vec3(), vec3(), 0.0};

                if (Sphere sphere(sphereCenter, sphereRadius, sphereMaterial); sphere.RayIntersection(ray) < 0) {
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