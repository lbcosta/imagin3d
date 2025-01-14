//
// Created by lbcos on 14/01/2025.
//

#include "Canvas.h"
#include "raylib.h"

Canvas::Canvas(const int width, const int height, const int nRow, const int nCol) {
    this->width = width;
    this->height = height;
    this->nRow = nRow;
    this->nCol = nCol;

    InitWindow(this->width, this->height, "Imagin3D");
    SetTargetFPS(60);
}

void Canvas::Draw() const {
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(GRAY);
        for (int row = 0; row <= this->nRow; row++) {
            for (int col = 0; col <= this->nCol; col++) {
                Color pixel;
                if (row > this->nRow / 2) {
                    pixel = {230, 41, 55, 255};
                } else {
                    pixel = {41, 230, 55, 255};
                }

                DrawPixel(col, row, pixel);
            }
        }

        EndDrawing();
    }

    CloseWindow();
}
