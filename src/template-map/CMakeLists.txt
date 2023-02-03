## application name
set( APP_NAME "template-map")

aux_source_directory(. SRC_LIST)
add_executable(${APP_NAME} ${SRC_LIST})

