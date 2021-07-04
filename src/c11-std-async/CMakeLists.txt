cmake_minimum_required(VERSION 3.13)
project(c11-std-async)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# c++ flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread" )

set(PROJECT_SOURCES
        main.cpp
)

add_executable(${CMAKE_PROJECT_NAME} ${PROJECT_SOURCES})

