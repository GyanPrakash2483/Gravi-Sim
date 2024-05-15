#include "particle.hpp"
#include "vectorops.hpp"



bool operator==(Particle p1, Particle p2) {
    return (p1.mass == p2.mass && p1.pos == p2.pos && p1.vel == p2.vel);
}//
// Created by gyan on 5/15/24.
//
