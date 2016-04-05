## application name
set( APP_NAME "program_options")

## project name
project( ${APP_NAME} )

## require a minimum version of CMake
cmake_minimum_required ( VERSION 2.6 FATAL_ERROR )

## add definitions, compiler switches, etc.
add_definitions( -Wall -O2 )
set( CMAKE_CXX_FLAGS -g )

## include (or not) the full compiler output
set( CMAKE_VERBOSE_MAKEFILE OFF )

## find boost package
find_package( Boost COMPONENTS program_options REQUIRED )

## include directories
include_directories( 
	${Boost_INCLUDE_DIRS}
)

## library paths
link_directories(
	${Boost_LIBRARY_DIRS}
)

set( LIBS
)

## sources
set ( SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

## executable
add_executable( ${APP_NAME} ${SOURCES} )

## link
target_link_libraries( ${APP_NAME} ${LIBS} ${Boost_LIBRARIES} )


