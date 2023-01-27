set(APP_NAME "c17-std-any")

aux_source_directory(. SRC_LIST)
add_executable(${APP_NAME} ${SRC_LIST})

set_property(TARGET ${APP_NAME} PROPERTY CXX_STANDARD 17)

# another way:
# target_compile_features(${APP_NAME} PRIVATE cxx_std_17)
