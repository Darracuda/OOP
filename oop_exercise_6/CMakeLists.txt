cmake_minimum_required(VERSION 3.21)
project(oop_exercise_6)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(oop_exercise_6
        figure.cpp
        figure.h
        main.cpp
        point.cpp
        point.h
        tallocator.cpp
        tallocator.h
        tbinarytree.cpp
        tbinarytree.h
        tbinarytreeitem.cpp
        tbinarytreeitem.h
        titterator.cpp
        titterator.h
        tlinkedlist.cpp
        tlinkedlist.h
        tlinkedlistitem.cpp
        tlinkedlistitem.h
        triangle.cpp
        triangle.h
        tvector.cpp
        tvector.h)
