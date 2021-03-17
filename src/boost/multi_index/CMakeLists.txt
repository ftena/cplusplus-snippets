####################################
####   TRKSVR_TACT
####################################

## application name
SET( APP_NAME "multi_index")

## project name
PROJECT( ${APP_NAME} )

## require a minimum version of CMake
CMAKE_MINIMUM_REQUIRED ( VERSION 2.6 FATAL_ERROR )

## add definitions, compiler switches, etc.
ADD_DEFINITIONS( -Wall -O2 )
SET( CMAKE_CXX_FLAGS -g )

## include (or not) the full compiler output
SET( CMAKE_VERBOSE_MAKEFILE OFF )

## find boost package
FIND_PACKAGE( Boost 1.34.1 EXACT )

## include directories
INCLUDE_DIRECTORIES ( 
	${Boost_INCLUDE_DIRS}
   $ENV{S80IFHMIROOT}/include 
   $ENV{S80IFHMIROOT}/include/S80_QtControls 
   $ENV{S80IFHMIROOT}/include/S80_QtStyle2 
   $ENV{S80ROOT}/source/ServiceApplications/InfrastructureFrameworks/include
   $ENV{S80ROOT}/source/ServiceApplications/SystemManagement/include
   $ENV{ACE_ROOT}
   $ENV{TAO_ROOT}/orbsvcs
   $ENV{TAO_ROOT}
   $ENV{TAO_ROOT}/tao
   $ENV{S80TOPICS}/include/tracksvr
   $ENV{S80TOPICS}/include/ais
   $ENV{S80TOPICS}/include/radar
   $ENV{S80TOPICS}/include/common
   $ENV{S80TOPICS}/include/ew
   $ENV{S80TOPICS}/include/per
   $ENV{S80TOPICS}/include/link
   $ENV{QTDIR}/include
   $ENV{QTDIR}/plugins/designer/include
   ${CMAKE_SOURCE_DIR}/wrappers
   ${CMAKE_SOURCE_DIR}/include
   ${MANAGER_DIR}/manager
   ${MANAGER_DIR}/comm
   ${MANAGER_DIR}/qt_generated_headers
   ${PANELS_DIRS}
   $ENV{LIBADN_HOME}/include/adn
   $ENV{LIBEWSCD_HOME}/include/ewscd/
)

## library paths
LINK_DIRECTORIES(
	${Boost_LIBRARY_DIRS}
   $ENV{S80IFHMIROOT}/lib
   $ENV{S80IFHMIROOT}/lib/S80_QtControls
   $ENV{S80TOPICS}/lib/ipcs2
   $ENV{S80TOPICS}/lib/tracksvr
   $ENV{S80TOPICS}/lib/ais
   $ENV{S80TOPICS}/lib/common
   $ENV{S80TOPICS}/lib/radar
   $ENV{S80TOPICS}/lib/planning
   $ENV{S80TOPICS}/lib/per
   $ENV{S80TOPICS}/lib/nav
   $ENV{S80TOPICS}/lib/ew
   $ENV{S80TOPICS}/lib/link
   $ENV{ACE_ROOT}/lib
   $ENV{OSPL_HOME}/lib
   $ENV{S80ROOT}/source/lib
   $ENV{QTDIR}/lib
   $ENV{S80LIB}/lib
   $ENV{LIBADN_HOME}/lib
   $ENV{LIBEWSCD_HOME}/lib/
   $ENV{S80TACSITROOT}/CommonS80Tacsit/lib
   ${CMAKE_SOURCE_DIR}/wrappers
)

SET ( TAO_LIBS TAO_CosNotification_Skel
               TAO_CosEvent_Skel
               TAO_CosNotification
               TAO_CosEvent
               TAO_CosNaming
               TAO_PortableServer
               TAO_AnyTypeCode
               TAO
               ACE   
)

SET( LIBS
      ${IFHMI_LIBS}
      ${IFHMI_S80_PLUGINS}
      ${TAO_LIBS}
      ${TOPICS_LIBS}
)

## sources
SET( SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/multi_index.cpp
)

## executable
ADD_EXECUTABLE( ${APP_NAME} ${SOURCES} )

## link
TARGET_LINK_LIBRARIES( ${APP_NAME} ${LIBS} )


