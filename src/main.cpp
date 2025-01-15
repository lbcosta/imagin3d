#include "raylib.h"
#include "lib/Math/vec3.h"

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

        vec3 rayOrigin(0.0f);
        float sphereRadius = 40.0f;
        vec3 sphereCenter(0.0f, 0.0f, -100.0f);

        float deltaY = WINDOW_HEIGHT / N_ROW;
        float deltaX = WINDOW_WIDTH / N_COL;
        Color pixel;

        for (int row = 0; row <= N_ROW; row++) {
            float y = (WINDOW_HEIGHT/2) - (deltaY/2) - (static_cast<float>(row) * deltaY);
            for (int col = 0; col <= N_COL; col++) {
                float x = (-WINDOW_WIDTH/2) + (deltaX/2) + (static_cast<float>(col) * deltaX);
                float z = -30.0f;
                vec3 intersectionPoint = {x, y, z};

                vec3 dr = intersectionPoint - rayOrigin;
                vec3 v = rayOrigin - sphereCenter;

                float a = dr.dot(dr);
                float b = 2 * v.dot(dr);
                float c = v.dot(v) - sphereRadius * sphereRadius;

                float discriminant = b * b - 4 * a * c;

                if (discriminant < 0) {
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