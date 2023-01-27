set(APP_NAME "chrono")
aux_source_directory(. SRC_LIST)
add_executable(${APP_NAME} ${SRC_LIST})

# properties
set_property(TARGET ${APP_NAME} PROPERTY CXX_STANDARD 14)

# c++ flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread" )
