cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)

add_executable(exp1 exp1.cpp)
add_library(exp1_lib exp1.cpp)