set( APP_NAME "program_options")

set( LIBS
	Boost::program_options
)

## sources
set ( SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

## executable
add_executable( ${APP_NAME} ${SOURCES} )

target_link_libraries( ${APP_NAME} ${LIBS} )
