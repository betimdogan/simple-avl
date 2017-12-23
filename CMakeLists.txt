cmake_minimum_required(VERSION 3.6)
project(HW4)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES main.cpp Node.cpp Node.h AVL.cpp AVL.h)
add_executable(HW4 ${SOURCE_FILES})