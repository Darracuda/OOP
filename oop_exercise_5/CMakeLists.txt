cmake_minimum_required(VERSION 3.21)
project(oop_exercise_5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(oop_exercise_5
        figure.cpp
        figure.h
        main.cpp
        point.cpp
        point.h
        titterator.cpp
        titterator.h
        tlinkedlist.cpp
        tlinkedlist.h
        tlinkedlistitem.cpp
        tlinkedlistitem.h
        triangle.cpp
        triangle.h)
