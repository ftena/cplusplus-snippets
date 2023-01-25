set( APP_NAME "cicular_buffer")

## sources
set( SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

## executable
add_executable( ${APP_NAME} ${SOURCES} )

target_include_directories( ${APP_NAME} PUBLIC ${Boost_INCLUDE_DIRS} ) 


