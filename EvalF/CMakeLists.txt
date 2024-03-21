cmake_minimum_required(VERSION 3.27.0)
project(Exam1)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_library(q2_1 q2_1.cpp)
add_library(q2_2 q2_2.cpp)

enable_testing()

add_subdirectory(test)
