## find boost package
find_package(Boost COMPONENTS system program_options REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread") # TODO: required at this point

add_subdirectory(asio/timer.1)
add_subdirectory(asio/timer.2)
add_subdirectory(asio/timer.3)

add_subdirectory(bind/example1)
add_subdirectory(bind/example2)

add_subdirectory(boost.units)

add_subdirectory(circular_buffer)

add_subdirectory(multi_index)

add_subdirectory(program_options)

add_subdirectory(ptr_vector)