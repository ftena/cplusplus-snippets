## lib name
set( LIB_NAME "foo" )

## project name
project( ${LIB_NAME} )

## require a minimum version of CMake
cmake_minimum_required ( VERSION 2.6 FATAL_ERROR )

## add definitions, compiler switches, etc.
add_definitions ( -Wall -O2 )
add_definitions ( -fprofile-arcs -ftest-coverage )
set( CXX_FLAGS"-g" )

## include (or not) the full compiler output
set( CMAKE_VERBOSE_MAKEFILE OFF )

## sources
set( SOURCES foo.h foo.cpp )

## library
add_library( ${LIB_NAME} SHARED ${SOURCES} )

target_link_libraries (${LIB_NAME} gcov)

