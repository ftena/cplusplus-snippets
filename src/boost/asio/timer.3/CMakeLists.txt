SET( APP_NAME "asio-timer3")

SET( LIBS
	Boost::system
)

## sources
SET( SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

## executable
add_executable( ${APP_NAME} ${SOURCES} )

## link
target_link_libraries( ${APP_NAME} ${LIBS} )


