cmake_minimum_required(VERSION 3.6)
project(Part_2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Point.cpp Point.h Grid.cpp Grid.h)
add_executable(Part_2 ${SOURCE_FILES})