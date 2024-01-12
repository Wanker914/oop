cmake_minimum_required(VERSION 3.27)
project(LR02_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(LR02_cpp
        main.cpp
        Shape.h
        Triange.h
        Quadrate.h
        Factory.h
        Factory.cpp
        Menu.h
        Menu.cpp
)
