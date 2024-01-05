cmake_minimum_required(VERSION 3.27)
project(LR4_cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(LR4_cpp
        main4.cpp
        MARSHTest.cpp
        MARSHTest.h
        MARSH.h)
