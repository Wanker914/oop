cmake_minimum_required(VERSION 3.27)
project(LR03_cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(LR03_cpp
        main.cpp
        Queue.h
        TestQueue.cpp
        TestQueue.h)
