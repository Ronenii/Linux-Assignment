cmake_minimum_required(VERSION 3.25)
project(Program1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Program1 main.cpp)
target_link_directories(Program1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Program1 shared_library)
