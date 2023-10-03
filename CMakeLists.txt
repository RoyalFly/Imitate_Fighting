cmake_minimum_required(VERSION 3.26)
project(Imitate_Fighting)

set(CMAKE_CXX_STANDARD 17)

add_executable(Imitate_Fighting Src/main.cpp
        Inc/robot.h
        Src/robot.cpp)
