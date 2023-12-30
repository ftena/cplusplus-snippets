set(APP_NAME "c20-std-execution")

aux_source_directory(. SRC_LIST)
add_executable(${APP_NAME} ${SRC_LIST})

set_property(TARGET ${APP_NAME} PROPERTY CXX_STANDARD 20)
