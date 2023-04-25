cmake_minimum_required(VERSION 3.25)
project(program3)

set(CMAKE_CXX_STANDARD 17)
link_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(program3 main.cpp)
target_link_libraries(program3 shared_library)
