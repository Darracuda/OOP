cmake_minimum_required(VERSION 3.21)
project(oop_exercise_02)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(oop_exercise_02
        BritishMoney.cpp
        BritishMoney.h
        main.cpp)
