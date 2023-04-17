cmake_minimum_required(VERSION 3.25)
project(shared_library)

set(CMAKE_CXX_STANDARD 17)

add_executable(shared_library main.cpp AirportFlights.cpp AirportFlights.h Flight.cpp Flight.h)
