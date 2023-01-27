set(PROJECT_SOURCES
        main.cpp
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread") # TODO: required at this point

add_executable(${CMAKE_PROJECT_NAME} ${PROJECT_SOURCES})

