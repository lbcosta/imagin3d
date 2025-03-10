//
// Created by lbcos on 09/03/2025.
//

#include "Transformable.h"

Transformable *Transformable::Translate(vec3 t) {
    this->transformer.Append({
        {1, 0, 0, t.x},
        {0, 1, 0, t.y},
        {0, 0, 1, t.z},
        {0, 0, 0, 1}
    });

    return this;
}

Transformable *Transformable::Scale(vec3 s, vec3 reference) {
    this->Translate({reference.x - 0, reference.y - 0, reference.z - 0});
    this->transformer.Append({
        {s.x, 0, 0, 0},
        {0, s.y, 0, 0},
        {0, 0, s.z, 0},
        {0, 0, 0, 1}
    });
    this->Translate({0 - reference.x, 0 - reference.y, 0 - reference.z});

    return this;
}

vec3 Transformable::TransformPoint(vec3 p) const {
    vec4 p_4d(p.x, p.y, p.z, 1);
    vec4 new_p_4d = this->transformer.GetMatrix() * p_4d;
    return new_p_4d.xyz();
}