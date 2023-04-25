cmake_minimum_required(VERSION 3.25)
project(Program1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Program1 main.cpp AirportFlights.cpp Flight.cpp Functions.cpp)
