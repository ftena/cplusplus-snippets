## application name
set( APP_NAME "c++11_std_function")

aux_source_directory(. SRC_LIST)
add_executable(${APP_NAME} ${SRC_LIST})
