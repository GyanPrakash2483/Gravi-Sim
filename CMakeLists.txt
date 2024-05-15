cmake_minimum_required(VERSION 3.28)
project(particlesimulator)

set(CMAKE_CXX_STANDARD 20)

add_executable(particlesimulator main.cpp
        vectorops.cpp
        vectorops.hpp
        particle.cpp)
target_link_libraries(particlesimulator libraylib.a)
