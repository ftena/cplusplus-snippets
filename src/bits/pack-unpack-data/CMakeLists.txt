set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_executable(packunpack main.cpp Data.cpp)

target_include_directories(packunpack PUBLIC "${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}")
