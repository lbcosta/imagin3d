//
// Created by lbcos on 14/01/2025.
//

#ifndef VEC3_H
#define VEC3_H

class vec3 {
public:
    union {
        struct { double x, y, z; };
        struct { double r{}, g{}, b{}; };
    };

    vec3();
    vec3(double v);
    vec3(double x, double y, double z);

    vec3 operator+(const vec3& other) const;
    vec3 operator-(const vec3& other) const;
    vec3 operator*(double scalar) const;
    vec3 operator/(double scalar) const;

    double dot(const vec3& other) const;

    vec3 cross(const vec3& other) const;

    double magnitude() const;

    vec3 normalize() const;

    vec3 xy() const;
    vec3 yz() const;
    vec3 zx() const;

    vec3 rgb() const;
    vec3 gbr() const;
    vec3 brg() const;

    // para debugging
    void print() const;
};

#endif // VEC3_H
