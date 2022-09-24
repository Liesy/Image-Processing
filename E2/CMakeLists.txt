cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)

set(LIBS exp1_lib)

add_executable(exp2 exp2.cpp)
target_link_libraries(exp2 ${LIBS})