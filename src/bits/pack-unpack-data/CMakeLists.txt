cmake_minimum_required(VERSION 3.10)
# project name
project(PackUnpack)

# application name
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_executable(PackUnpack main.cpp Data.cpp)

target_include_directories(PackUnpack PUBLIC "${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}")
