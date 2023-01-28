## application name
set( APP_NAME "bar" )

## use or not gcov
option(ENABLE_GCOV "Enable gcov" OFF)

## add definitions, compiler switches, etc.
add_definitions( -Wall -O2 )
if(ENABLE_GCOV)
    add_definitions( -fprofile-arcs -ftest-coverage )
endif(ENABLE_GCOV)
set( CMAKE_CXX_FLAGS -g )

## sources
set( SOURCES main.cpp )

## executable
add_executable(${APP_NAME} ${SOURCES}) 
target_link_libraries(${APP_NAME} foo)

if(ENABLE_GCOV)
    target_link_libraries(${PROJECT_NAME} gcov)
endif(ENABLE_GCOV)

