cmake_minimum_required(VERSION 3.21)
project(oop_exercise_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(oop_exercise_3
        figure.cpp
        figure.h
        main.cpp
        point.cpp
        point.h
        tlinkedlist.cpp
        tlinkedlist.h
        triangle.cpp
        triangle.h)
