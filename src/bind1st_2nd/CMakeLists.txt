set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

aux_source_directory(. SRC_LIST)
add_executable(bind1st_2nd ${SRC_LIST})
