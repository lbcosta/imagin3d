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
        // Fundo
            new Plane({0, -150, 0},{0, 1, 0}, WATER_TEXTURE), // Oceano
            new Plane({200, -150, -2000},{0, 0, 1}, SKY_TEXTURE), // Horizonte
        // Ilha
            new Cylinder({0, -150, -500},200,30,{0, 1, 0}, GROUND_BROWN),
            new Sphere({0, -150, -500},200,GRASS_GREEN),
        // Farol
            new Cylinder({0, 10, -500},50,50,{0, 1, 0}, WALL_GRAY),
            new Cylinder({0, 60, -500},50,50,{0, 1, 0}, BRICK_ORANGE),
            new Cylinder({0, 110, -500},50,50,{0, 1, 0}, WALL_GRAY),
            new Cylinder({0, 160, -500},50,50,{0, 1, 0}, BRICK_ORANGE),
            new Cylinder({0, 210, -500},50,50,{0, 1, 0}, WALL_GRAY),
            new Cylinder({0, 260, -500},50,50,{0, 1, 0}, BRICK_ORANGE),
            new Cylinder({0, 310, -500},50,20,{0, 1, 0}, POWDER_BLUE),
            new Cone({0, 330, -500},50,100,{0, 1, 0},DUSTY_BROWN),
    };

    vec3 houseBaseCenter = {45, 45, -430};
    auto houseBase = new Cube(houseBaseCenter,45,WALL_GRAY);
    houseBase->Scale({2, 0, 0}, houseBaseCenter)->Transform();

    vec3 houseRoof1Center = {45, 90, -430};
    auto houseRoof1 = new Cube(houseRoof1Center,45,BRICK_ORANGE);
    houseRoof1
        ->Translate({-15, -15, 0})
        ->Scale({2, 0, 0}, houseRoof1Center)
        ->Shear(45, XY, X, houseRoof1Center)
        ->Scale({0.25, 0.4, 0}, houseRoof1Center)
    ->Transform();

    vec3 houseRoof2Center = {45, 90, -430};
    auto houseRoof2 = new Cube(houseRoof2Center,45,BRICK_ORANGE);
    houseRoof2
        ->Translate({5, 0, 0})
        ->Reflect({45, 90, -430}, {45, 60, -460}, {45, 120, -490})
        ->Translate({-15, -15, 0})
        ->Scale({2, 0, 0}, houseRoof2Center)
        ->Shear(45, XY, X, houseRoof2Center)
        ->Scale({0.25, 0.4, 0}, houseRoof2Center)
        ->Transform();


    vec3 doorCenter = {45, 45, -415};
    auto door = new Cube(doorCenter,45,GROUND_BROWN);
    door
        ->Translate({0, -5, 0})
        ->Scale({0.5, 0.75, 0.5}, doorCenter)
        ->Transform();

    objects.push_back(houseBase);
    objects.push_back(houseRoof1);;
    objects.push_back(houseRoof2);
    objects.push_back(door);

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