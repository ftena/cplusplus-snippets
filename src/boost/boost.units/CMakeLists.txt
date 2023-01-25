set( APP_NAME "units")

## sources
set( SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/units.cpp
)

## executable
add_executable( ${APP_NAME} ${SOURCES} )

target_include_directories( ${APP_NAME} PUBLIC ${Boost_INCLUDE_DIRS} ) 


