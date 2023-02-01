set( APP_NAME "ptr_vector")

## sources
set( SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

## executable
add_executable( ${APP_NAME} ${SOURCES} )

## to locate boost headers
target_include_directories( ${APP_NAME} PUBLIC ${Boost_INCLUDE_DIRS} ) 