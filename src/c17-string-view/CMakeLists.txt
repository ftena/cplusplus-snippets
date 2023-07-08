set(APP_NAME "c17-string-view")

aux_source_directory(. SRC_LIST)
add_executable(${APP_NAME} ${SRC_LIST})

set_property(TARGET ${APP_NAME} PROPERTY CXX_STANDARD 17)

