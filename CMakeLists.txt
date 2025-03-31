cmake_minimum_required(VERSION 3.29)
project(kalkulator)

set(CMAKE_CXX_STANDARD 14)

add_executable(kalkulator
        Calculator.cpp
        calculator.h
        main.cpp)
