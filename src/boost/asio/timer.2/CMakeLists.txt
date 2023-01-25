SET( APP_NAME "asio-timer2")

SET( LIBS
	Boost::system
)

## sources
SET( SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

## executable
ADD_EXECUTABLE( ${APP_NAME} ${SOURCES} )

## link
TARGET_LINK_LIBRARIES( ${APP_NAME} ${LIBS} )


