cmake_minimum_required(VERSION 4.2.3)
project(Airplaneboarding)

set(CMAKE_CXX_STANDARD 20)

add_executable(Airplaneboarding main.c
        run_simulation.c
        run_simulation.h)
add_executable(run_simulation run_simulation.c run_simulation.h)
