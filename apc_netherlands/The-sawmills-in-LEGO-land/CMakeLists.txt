cmake_minimum_required(VERSION 3.0.0)

project(apc)

add_executable(start main.cpp solution/solution.cpp)
include_directories(solution)