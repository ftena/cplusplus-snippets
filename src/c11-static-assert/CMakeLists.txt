cmake_minimum_required(VERSION 3.5)
project(static-assert)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCES
        main.cpp
)

add_executable(static-assert
    ${PROJECT_SOURCES}
)
