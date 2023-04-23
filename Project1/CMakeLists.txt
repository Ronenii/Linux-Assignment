cmake_minimum_required(VERSION 3.25)
project(Project1)

set(CMAKE_CXX_STANDARD 17)

find_library(MYLIB NAMES libshared_library.so PATHS ${CMAKE_CURRENT_SOURCE_DIR} )


add_executable(Project1 main.cpp)

target_link_libraries(Project1 MYLIB)
