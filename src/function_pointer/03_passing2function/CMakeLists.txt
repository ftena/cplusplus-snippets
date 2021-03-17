## application name
set( APP_NAME "passing2function" )

aux_source_directory(. SRC_LIST)
add_executable(${APP_NAME} ${SRC_LIST})
