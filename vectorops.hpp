//
// Created by gyan on 5/15/24.
//

#ifndef PARTICLESIMULATOR_VECTOROPS_HPP
#define PARTICLESIMULATOR_VECTOROPS_HPP

#include "particle.hpp"

bool operator==(Vector2 v1, Vector2 v2);
bool operator!=(Vector2 v1, Vector2 v2);
Vector2 operator+(Vector2 v1, Vector2 v2);
Vector2 operator-(Vector2 v1, Vector2 v2);
Vector2 operator*(float sclr, Vector2 v);

#endif //PARTICLESIMULATOR_VECTOROPS_HPP
