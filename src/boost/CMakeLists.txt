## find boost package
find_package(Boost COMPONENTS system REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread") # TODO: required at this point

add_subdirectory(asio/timer.1)
add_subdirectory(asio/timer.2)
add_subdirectory(asio/timer.3)