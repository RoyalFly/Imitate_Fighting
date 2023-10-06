cmake_minimum_required(VERSION 3.26)
project(Imitate_Fighting)

set(CMAKE_CXX_STANDARD 17)

add_executable(Imitate_Fighting Src/main.cpp
        Inc/robot.h
        Src/robot.cpp
        Inc/main.h
        Inc/Architect.h
        Src/Architect.cpp
        Src/Tick_Simulate.cpp
        Src/Hero.cpp
        Src/Sentinel.cpp
        Inc/Action.h
        Inc/Sentinel.h
        Inc/Tick_Simulate.h
        Inc/Infantry.h
        Inc/Infantry.h
        Src/Infantry.cpp
)
