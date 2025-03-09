//
// Created by lbcos on 11/02/2025.
//

#include "PolygonMesh.h"

PolygonMesh::PolygonMesh(vector<vec3> vertices, ObjectMaterial material) {
    this->type = MESH;
    this->material = material;

    for (int idx = 0; idx < vertices.size(); idx = idx + 3) {
        this->triangles.emplace_back(vertices[idx], vertices[idx + 1], vertices[idx + 2], material);
    }
}


double PolygonMesh::RayIntersection(VectorRay ray) {
    double closestIntersection = -1;
    for (Triangle& triangle : this->triangles) {
        double intersectionMoment = triangle.RayIntersection(ray);
        if (intersectionMoment > 0.0 && (closestIntersection < 0 || intersectionMoment < closestIntersection)) {
            closestIntersection = intersectionMoment;
        }
    }

    return closestIntersection;
}

vec3 PolygonMesh::Normal(VectorRay ray) {
    Triangle* closestTriangle = nullptr;
    double closestIntersection = -1;
    for (Triangle& triangle : this->triangles) {
        double intersectionMoment = triangle.RayIntersection(ray);
        if (intersectionMoment > 0.0 && (closestIntersection < 0 || intersectionMoment < closestIntersection)) {
            closestTriangle = &triangle;
            closestIntersection = intersectionMoment;
        }
    }

    if (closestTriangle == nullptr) {
        return 0;
    }

    return closestTriangle->Normal(ray);
}

void PolygonMesh::Transform() {}

