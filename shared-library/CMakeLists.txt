cmake_minimum_required(VERSION 3.25)
project(shared_library)

set(CMAKE_CXX_STANDARD 17)

# Add source files for the library
add_library(shared_library SHARED
        AirportFlights.cpp
        Flight.cpp
        Functions.cpp)





