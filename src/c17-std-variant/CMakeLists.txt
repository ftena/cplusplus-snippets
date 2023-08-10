set(APP_NAME "c17-std-variant")

aux_source_directory(. SRC_LIST)
add_executable(${APP_NAME} ${SRC_LIST})

target_compile_features(${APP_NAME} PRIVATE cxx_std_17)

# another way:
# set_property(TARGET ${APP_NAME} PROPERTY CXX_STANDARD 17)
