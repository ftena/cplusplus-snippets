## application name
set( APP_NAME "pointer_to_member_function")

aux_source_directory(. SRC_LIST)
add_executable(${APP_NAME} ${SRC_LIST})
