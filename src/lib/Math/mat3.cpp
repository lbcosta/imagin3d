//
// Created by lbcos on 07/02/2025.
//

#include "mat3.h"
#include <iostream>
#include <stdexcept>

vec3& mat3::operator[](int index) { return rows[index]; }
const vec3& mat3::operator[](int index) const { return rows[index]; }

mat3 mat3::operator+(const mat3& other) const {
    return {rows[0] + other.rows[0], rows[1] + other.rows[1], rows[2] + other.rows[2]};
}

mat3 mat3::operator-(const mat3& other) const {
    return {rows[0] - other.rows[0], rows[1] - other.rows[1], rows[2] - other.rows[2]};
}

mat3 mat3::operator*(double scalar) const {
    return {rows[0] * scalar, rows[1] * scalar, rows[2] * scalar};
}

mat3 mat3::operator*(const mat3& other) const {
    mat3 result;
    for (int i = 0; i < 3; ++i) {
        result[i] = vec3(
            rows[i].dot(vec3(other[0].x, other[1].x, other[2].x)),
            rows[i].dot(vec3(other[0].y, other[1].y, other[2].y)),
            rows[i].dot(vec3(other[0].z, other[1].z, other[2].z))
        );
    }
    return result;
}

vec3 mat3::operator*(const vec3& v) const {
    return {rows[0].dot(v), rows[1].dot(v), rows[2].dot(v)};
}

double mat3::determinant() const {
    return rows[0].x * (rows[1].y * rows[2].z - rows[1].z * rows[2].y) -
           rows[0].y * (rows[1].x * rows[2].z - rows[1].z * rows[2].x) +
           rows[0].z * (rows[1].x * rows[2].y - rows[1].y * rows[2].x);
}

mat3 mat3::transpose() const {
    return {
        vec3(rows[0].x, rows[1].x, rows[2].x),
        vec3(rows[0].y, rows[1].y, rows[2].y),
        vec3(rows[0].z, rows[1].z, rows[2].z)
    };
}

mat3 mat3::inverse() const {
    double det = determinant();
    if (det == 0) throw std::runtime_error("Matriz singular, não tem inversa!");
    double invDet = 1.0 / det;
    return mat3(
        vec3(
            (rows[1].y * rows[2].z - rows[1].z * rows[2].y) * invDet,
            (rows[0].z * rows[2].y - rows[0].y * rows[2].z) * invDet,
            (rows[0].y * rows[1].z - rows[0].z * rows[1].y) * invDet
        ),
        vec3(
            (rows[1].z * rows[2].x - rows[1].x * rows[2].z) * invDet,
            (rows[0].x * rows[2].z - rows[0].z * rows[2].x) * invDet,
            (rows[0].z * rows[1].x - rows[0].x * rows[1].z) * invDet
        ),
        vec3(
            (rows[1].x * rows[2].y - rows[1].y * rows[2].x) * invDet,
            (rows[0].y * rows[2].x - rows[0].x * rows[2].y) * invDet,
            (rows[0].x * rows[1].y - rows[0].y * rows[1].x) * invDet
        )
    );
}

mat3 mat3::OuterProduct(const vec3& v1, const vec3& v2) {
    return mat3(
        vec3(v1.x * v2.x, v1.x * v2.y, v1.x * v2.z),
        vec3(v1.y * v2.x, v1.y * v2.y, v1.y * v2.z),
        vec3(v1.z * v2.x, v1.z * v2.y, v1.z * v2.z)
    );
}