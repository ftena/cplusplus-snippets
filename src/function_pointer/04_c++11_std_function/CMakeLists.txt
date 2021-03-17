## application name
set( APP_NAME "c++11_std_function")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
aux_source_directory(. SRC_LIST)
add_executable(${APP_NAME} ${SRC_LIST})
