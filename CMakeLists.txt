cmake_minimum_required(VERSION 3.10)
project(ImageProcessing)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)

include_directories("${PROJECT_SOURCE_DIR}/include")

add_subdirectory(E1)
add_subdirectory(E2)