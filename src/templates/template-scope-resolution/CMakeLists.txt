project(template-scope-resolution)
cmake_minimum_required(VERSION 2.8)

## application name
set(APP_NAME "template-scope-resolution")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
aux_source_directory(. SRC_LIST)
add_executable(${APP_NAME} ${SRC_LIST})
