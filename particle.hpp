//
// Created by gyan on 5/15/24.
//

#ifndef PARTICLESIMULATOR_PARTICLE_HPP
#define PARTICLESIMULATOR_PARTICLE_HPP

#include <raylib.h>

const static float G = 1000;

typedef struct Particle {
    float mass;
    Vector2 pos;
    Vector2 vel;
} Particle;

bool operator==(Particle p1, Particle p2);

#endif //PARTICLESIMULATOR_PARTICLE_HPP
