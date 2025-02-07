//
// Created by lbcos on 07/02/2025.
//

#ifndef MAT3_H
#define MAT3_H

#include "vec3.h"

class mat3 {
public:
    vec3 rows[3];

    mat3() : rows{vec3(), vec3(), vec3()} {}
    mat3(const vec3& row0, const vec3& row1, const vec3& row2) : rows{row0, row1, row2} {}
    mat3(double diagonal) : rows{vec3(diagonal, 0, 0), vec3(0, diagonal, 0), vec3(0, 0, diagonal)} {}

    vec3& operator[](int index);
    const vec3& operator[](int index) const;

    mat3 operator+(const mat3& other) const;

    mat3 operator-(const mat3& other) const;

    mat3 operator*(double scalar) const;

    mat3 operator*(const mat3& other) const;

    vec3 operator*(const vec3& v) const;

    double determinant() const;

    mat3 transpose() const;

    mat3 inverse() const;

    static mat3 OuterProduct(const vec3& v1, const vec3& v2);
};

#endif //MAT3_H
