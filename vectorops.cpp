//
// Created by gyan on 5/15/24.
//

#include "vectorops.hpp"

bool operator==(Vector2 v1, Vector2 v2) {
    return (v1.x == v2.x && v1.y == v2 .y);
}

bool operator!=(Vector2 v1, Vector2 v2) {
    return !(v1 == v2);
}

Vector2 operator+(Vector2 v1, Vector2 v2) {
    Vector2 sum = {
            .x = v1.x + v2.x,
            .y = v1.y + v2.y
    };
    return sum;
}

Vector2 operator-(Vector2 v1, Vector2 v2) {
    Vector2 diff = {
            .x = v1.x - v2.x,
            .y = v1.y - v2.y
    };
    return diff;
}

Vector2 operator*(float sclr, Vector2 v) {
    Vector2 prod = {
            .x = sclr * v.x,
            .y = sclr * v.y
    };
    return prod;
}
