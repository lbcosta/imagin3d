#include "raylib.h"
#include "lib/Math/vec3.h"
#include "lib/Sphere/Sphere.h"
#include "lib/Cylinder/Cylinder.h"
#include "lib/Cone/Cone.h"
#include "lib/Plane/Plane.h"
#include "lib/Cube/Cube.h"
#include "lib/Scene/Scene.h"
#include "lib/Plane/Textures.h"
#include "lib/Object/Colors.h"

auto PROJECT_TITLE = "Imagin3D";

int main() {
    InitWindow(CANVAS_WIDTH, CANVAS_HEIGHT, PROJECT_TITLE);
    SetTargetFPS(FPS);

    vector<Object*> objects{
        new Plane({0, -150, 0},{0, 1, 0}, WOOD_TEXTURE), // Piso
        new Plane( {200, -150, 0},{-1, 0, 0}, POWDER_BLUE), // Parede Direita
        new Plane({200, -150, -400},{0, 0, 1}, POWDER_BLUE), // Parede de trás
        new Plane( {-200, -150, 0},{1, 0, 0}, POWDER_BLUE), // Parede Esquerda
        new Plane({0, 150, 0},{0, -1, 0}, POWDER_BLUE), // Telhado
        new Cylinder({0, -150, -200},5,90,{0, 1, 0}, DUSTY_BROWN), // Base da árvore
        new Cone({0, -60, -200},90,150,{0, 1, 0},TROPICAL_GREEN), // Árvore
        new Sphere({0, 95, -200},5,ANTIQUE_GOLD), // Globo de Natal
        new Cube({0, -150, -165},40,VIBRANT_PINK) // Presente de Natal
    };

    Scene scene(SceneParams{
        .LightPosition = {-100, 140, -20},
        .LightIntensity = {0.7, 0.7, 0.7},
        .AmbientLight = {0.3, 0.3, 0.3},
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