## application name
set( APP_NAME "bar" )

## project name
project( ${APP_NAME} )

## use or not gcov
option(ENABLE_GCOV "Enable gcov" OFF)

## require a minimum version of CMake
cmake_minimum_required ( VERSION 2.6 FATAL_ERROR )

## add definitions, compiler switches, etc.
add_definitions( -Wall -O2 )
if(ENABLE_GCOV)
    add_definitions( -fprofile-arcs -ftest-coverage )
endif(ENABLE_GCOV)
set( CMAKE_CXX_FLAGS -g )

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../lib/)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../lib/build/)

## sources
set( SOURCES main.cpp )

## executable
add_executable(${APP_NAME} ${SOURCES}) 
target_link_libraries(${PROJECT_NAME} foo)

if(ENABLE_GCOV)
    target_link_libraries(${PROJECT_NAME} gcov)
endif(ENABLE_GCOV)

