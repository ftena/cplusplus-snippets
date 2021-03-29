cmake_minimum_required(VERSION 3.13)
project(chrono LANGUAGES CXX)
aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})

# properties
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)

# c++ flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread" )
