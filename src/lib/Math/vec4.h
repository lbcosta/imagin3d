//
// Created by lbcos on 19/02/2025.
//

#include "vec3.h"

#ifndef VEC4_H
#define VEC4_H

class vec4 {
public:
    union {
        struct { double x, y, z, w; };
        struct { double r, g, b, a; };
    };

    vec4();
    vec4(double v);
    vec4(double x, double y, double z, double w);
    vec4(vec3 p);

    vec4 operator+(const vec4& other) const;
    vec4 operator-(const vec4& other) const;
    vec4 operator*(double scalar) const;
    vec4 operator/(double scalar) const;

    vec4 operator*(const vec4& other) const;

    double dot(const vec4& other) const;
    double magnitude() const;
    vec4 normalize() const;

    vec3 xyz() const;
    vec4 xyzw() const;

    vec4 rgba() const;
    vec4 bgra() const;

    // para debugging
    void print() const;
};

#endif // VEC4_H

