cmake_minimum_required(VERSION 3.17)
project(SparseLineMatrix)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(SparseLineMatrix
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        Matrix.cpp
        Matrix.h
        ShortTest.cpp
        ShortTest.h)
