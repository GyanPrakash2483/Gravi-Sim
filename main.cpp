#include <vector>
#include <raylib.h>
#include <raymath.h>
#include "particle.hpp"
#include "vectorops.hpp"
#include <cmath>
#include <iostream>

int main() {
    InitWindow(800, 450, "Gravity Simulator");
    SetTargetFPS(60);
    SetWindowState(FLAG_WINDOW_RESIZABLE);

    std::vector<Particle> particles;

    while(!WindowShouldClose()) {

        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            Particle newparticle = {
                    .mass = 1.0f,
                    .pos = {
                            .x = (float)GetMouseX(),
                            .y = (float)GetMouseY()
                    },
                    .vel = {
                            .x = 0.0f,
                            .y = 0.0f
                    }
            };
            particles.push_back(newparticle);
        }

        for(auto & particle1 : particles) {

            for(auto & particle2 : particles) {
                if(particle1 == particle2) continue;
                if (Vector2Distance(particle1.pos, particle2.pos) > 2) {
                    float accel_mag = G * particle2.mass / pow(Vector2Distance(particle1.pos, particle2.pos),
                                                               2); //magnitude of acceleration of p1 due to p2

                    float angle = atan((particle2.pos.y - particle1.pos.y) / (particle2.pos.x - particle1.pos.x));

                    Vector2 accel_vec = {
                            .x = accel_mag * cos(angle),
                            .y = accel_mag * sin(angle)
                    };

                    if (particle2.pos.x < particle1.pos.x) accel_vec.x = -abs(accel_vec.x);
                    if (particle2.pos.y < particle1.pos.y) accel_vec.y = -abs(accel_vec.y);
                    if (particle2.pos.x > particle1.pos.x) accel_vec.x = abs(accel_vec.x);
                    if (particle2.pos.y > particle1.pos.y) accel_vec.y = abs(accel_vec.y);

                    //std::cout << accel_vec.x << " " << accel_vec.y << std::endl;

                    particle1.vel.x += accel_vec.x;
                    particle1.vel.y += accel_vec.y;
                } else {
                    Vector2 dir = {
                            .x = particle2.pos.x - particle1.pos.x,
                            .y = particle2.pos.y - particle1.pos.y
                    };

                    float dirmag = sqrt(dir.x * dir.x + dir.y * dir.y);
                    dir.x /= dirmag;
                    dir.y /= dirmag;

                    particle1.vel = particle1.vel - dir;
                }

                particle1.pos.x += particle1.vel.x;
                particle1.pos.y += particle1.vel.y;
            }

            if(particle1.pos.x > GetScreenWidth()) {
                particle1.vel.x = -abs(particle1.vel.x);
            }
            if(particle1.pos.x < 0) {
                particle1.vel.x = abs(particle1.vel.x);
            }
            if(particle1.pos.y > GetScreenHeight()) {
                particle1.vel.y = -abs(particle1.vel.y);
            }
            if(particle1.pos.y < 0) {
                particle1.vel.y = abs(particle1.vel.y);
            }

            float velmag = sqrt(particle1.vel.x * particle1.vel.x + particle1.vel.y * particle1.vel.y);
            if(velmag > 5) {
                Vector2 dampvec = particle1.vel;
                dampvec.x /= velmag;
                dampvec.y /= velmag;

                particle1.vel = particle1.vel - 0.1f * dampvec;
            }

            velmag = sqrt(particle1.vel.x * particle1.vel.x + particle1.vel.y * particle1.vel.y);

            if(velmag > 10) {
                particle1.vel.x /= velmag;
                particle1.vel.y /= velmag;

                particle1.vel = 10 * particle1.vel;
            }

        }

        BeginDrawing();
            ClearBackground(BLACK);
        for(auto & particle : particles) {
            DrawCircle(particle.pos.x, particle.pos.y, 2.0f, WHITE);
        }
        EndDrawing();

    }

    CloseWindow();
    return 0;
}
