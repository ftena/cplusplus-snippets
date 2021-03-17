## application name
SET( APP_NAME "bind")

## project name
PROJECT( ${APP_NAME} )

## require a minimum version of CMake
CMAKE_MINIMUM_REQUIRED ( VERSION 2.6 FATAL_ERROR )

## add definitions, compiler switches, etc.
ADD_DEFINITIONS( -Wall -O2 )
SET( CMAKE_CXX_FLAGS -g )

## include (or not) the full compiler output
SET( CMAKE_VERBOSE_MAKEFILE OFF )

## find boost package
FIND_PACKAGE( Boost 1.56.0 EXACT )

## include directories
INCLUDE_DIRECTORIES ( 
	${Boost_INCLUDE_DIRS}
)

## library paths
LINK_DIRECTORIES(
	${Boost_LIBRARY_DIRS}
)

SET( LIBS
)

## sources
SET( SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

## executable
ADD_EXECUTABLE( ${APP_NAME} ${SOURCES} )

## link
TARGET_LINK_LIBRARIES( ${APP_NAME} ${LIBS} )


