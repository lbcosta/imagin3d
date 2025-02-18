//
// Created by lbcos on 10/02/2025.
//

#include "Cube.h"

Cube::Cube(vec3 center, double size, ObjectMaterial material): PolygonMesh() {
    this->type = MESH;
    this->material = material;

    double h = size / 2.0;

    vec3 vertices[8] = {
        { center.x - h, center.y - h, center.z - h },
        { center.x + h, center.y - h, center.z - h },
        { center.x + h, center.y + h, center.z - h },
        { center.x - h, center.y + h, center.z - h },
        { center.x - h, center.y - h, center.z + h },
        { center.x + h, center.y - h, center.z + h },
        { center.x + h, center.y + h, center.z + h },
        { center.x - h, center.y + h, center.z + h },
    };

    this->triangles = {
        {vertices[0], vertices[1], vertices[2], material},
        {vertices[0], vertices[2], vertices[3], material},
        {vertices[4], vertices[5], vertices[6], material},
        {vertices[4], vertices[6], vertices[7], material},
        {vertices[0], vertices[1], vertices[5], material},
        {vertices[0], vertices[5], vertices[4], material},
        {vertices[2], vertices[3], vertices[7], material},
        {vertices[2], vertices[7], vertices[6], material},
        {vertices[0], vertices[3], vertices[7], material},
        {vertices[0], vertices[7], vertices[4], material},
        {vertices[1], vertices[2], vertices[6], material},
        {vertices[1], vertices[6], vertices[5], material}
    };
}
