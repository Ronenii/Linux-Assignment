cmake_minimum_required(VERSION 3.25)
project(program4)

set(CMAKE_CXX_STANDARD 17)

link_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(program4 main.cpp)
target_link_libraries(program4 shared_library)