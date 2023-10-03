cmake_minimum_required(VERSION 3.26)
project(Imitate_Fighting)

set(CMAKE_CXX_STANDARD 17)

add_executable(Imitate_Fighting Src/main.cpp
        Inc/robot.h
        Src/robot.cpp
        Inc/main.h
        Src/robot_init.cpp
        Inc/Architect.h
        Src/Architect_Init.cpp
        Src/Tick_Simulate.cpp
        Src/Hero.cpp
)
