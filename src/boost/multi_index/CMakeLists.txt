## application name
set( APP_NAME "multi_index")

## sources
set( SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/multi_index.cpp
)

## executable
add_executable( ${APP_NAME} ${SOURCES} )

target_include_directories( ${APP_NAME} PUBLIC ${Boost_INCLUDE_DIRS} ) 


