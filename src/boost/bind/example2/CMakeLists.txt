SET( APP_NAME "bind-ex2")

## sources
SET( SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

## executable
ADD_EXECUTABLE( ${APP_NAME} ${SOURCES} )

target_include_directories( ${APP_NAME} PUBLIC ${Boost_INCLUDE_DIRS} ) 


