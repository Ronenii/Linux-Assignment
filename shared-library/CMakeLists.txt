cmake_minimum_required(VERSION 3.25)
project(shared_library)

set(CMAKE_CXX_STANDARD 17)

add_executable(shared_library main.cpp Database.cpp Database.h Flight.cpp Flight.h)
