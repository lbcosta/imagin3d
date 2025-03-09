//
// Created by lbcos on 07/03/2025.
//

#ifndef MAT4_H
#define MAT4_H

#include "vec4.h"

class mat4 {
public:
    vec4 rows[4];

    mat4() : rows{vec4(), vec4(), vec4(), vec4()} {}
    mat4(const vec4& row0, const vec4& row1, const vec4& row2, const vec4& row3) : rows{row0, row1, row2, row3} {}
    mat4(double diagonal) : rows{vec4(diagonal, 0, 0, 0), vec4(0, diagonal, 0, 0), vec4(0, 0, diagonal, 0), vec4(0, 0, 0, diagonal)} {}

    vec4& operator[](int index);
    const vec4& operator[](int index) const;

    mat4 operator+(const mat4& other) const;

    mat4 operator-(const mat4& other) const;

    mat4 operator*(double scalar) const;

    mat4 operator*(const mat4& other) const;

    vec4 operator*(const vec4& v) const;
};



#endif //MAT4_H
