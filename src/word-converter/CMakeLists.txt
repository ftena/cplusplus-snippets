cmake_minimum_required(VERSION 3.13)
project(word_converter LANGUAGES CXX)

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_sources(${PROJECT_NAME} PRIVATE main.cpp WordConverter.cpp WordConverter.h)
target_link_libraries(${PROJECT_NAME} PRIVATE stdc++fs)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
