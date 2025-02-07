//
// Created by lbcos on 17/01/2025.
//

#ifndef VECTORRAY_H
#define VECTORRAY_H

#include "../Math/vec3.h"

class VectorRay {
  public:
    VectorRay(vec3 start, vec3 end);
    vec3 Origin() const;
    vec3 Direction() const;
  private:
    vec3 start;
    vec3 end;
};



#endif //VECTORRAY_H
