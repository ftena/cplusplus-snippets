## lib name
set( LIB_NAME "foo" )

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
 # All the directories following PUBLIC will be used for the current target
 # and the other targets that have dependencies on the current target.
target_include_directories(${LIB_NAME} PUBLIC .)

