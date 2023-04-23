cmake_minimum_required(VERSION 3.25)
project(shared_library)

set(CMAKE_CXX_STANDARD 17)

# Add source files for the library
add_library(shared_library SHARED
        AirportFlights.cpp
        Flight.cpp
        Functions.cpp ../Project1/main.cpp)

target_include_directories(shared_library PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        )
#add_executable(shared_library main.cpp AirportFlights.cpp AirportFlights.h Flight.cpp Flight.h)
