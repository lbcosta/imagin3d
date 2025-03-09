//
// Created by lbcos on 07/03/2025.
//

#include "mat4.h"

vec4& mat4::operator[](int index) { return rows[index]; }
const vec4& mat4::operator[](int index) const { return rows[index]; }

mat4 mat4::operator+(const mat4& other) const {
    return {rows[0] + other.rows[0], rows[1] + other.rows[1], rows[2] + other.rows[2], rows[3] + other.rows[3]};
}

mat4 mat4::operator-(const mat4& other) const {
    return {rows[0] - other.rows[0], rows[1] - other.rows[1], rows[2] - other.rows[2], rows[3] - other.rows[3]};
}

mat4 mat4::operator*(double scalar) const {
    return {rows[0] * scalar, rows[1] * scalar, rows[2] * scalar, rows[3] * scalar};
}

mat4 mat4::operator*(const mat4& other) const {
    mat4 result;
    for (int i = 0; i < 4; ++i) {
        result[i] = vec4(
            rows[i].dot(vec4(other[0].x, other[1].x, other[2].x, other[3].x)),
            rows[i].dot(vec4(other[0].y, other[1].y, other[2].y, other[3].y)),
            rows[i].dot(vec4(other[0].z, other[1].z, other[2].z, other[3].z)),
            rows[i].dot(vec4(other[0].w, other[1].w, other[2].w, other[3].w))
        );
    }
    return result;
}

vec4 mat4::operator*(const vec4& v) const {
    return {rows[0].dot(v), rows[1].dot(v), rows[2].dot(v), rows[3].dot(v)};
}
