## application name
set( APP_NAME "delete_vectors_and_lists")

aux_source_directory(. SRC_LIST)
add_executable(${APP_NAME} ${SRC_LIST})
