## application name
SET( APP_NAME "ports")

## sources
SET( SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/system_coordinator.cpp
)

## executable
ADD_EXECUTABLE( ${APP_NAME} ${SOURCES} )