cmake_minimum_required(VERSION 3.31)
project(actividadEDA_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(actividadEDA_1 source/main.cpp
        source/quickSort.cpp
        source/quickSort.h
        source/arbolAVL.cpp
        source/arbolAVL.h
        source/heapSort.cpp
        source/heapSort.h)
