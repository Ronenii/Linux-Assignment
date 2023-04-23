cmake_minimum_required(VERSION 3.25)
project(program2)

set(CMAKE_CXX_STANDARD 17)

link_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(program2 main.cpp)
target_link_libraries(program2 shared_library)
