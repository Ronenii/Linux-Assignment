cmake_minimum_required(VERSION 3.25)
project(shared_library)

set(CMAKE_CXX_STANDARD 17)

# Add source files for the library
add_library(shared_library SHARED
        main.cpp
        AirportFlights.cpp
        AirportFlights.h
        Flight.cpp
        Flight.h
        )

# Specify include directories
target_include_directories(shared_library PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        )

# Specify library output directory
set_target_properties(shared_library PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib"
        )

# Set compiler options
target_compile_options(shared_library PRIVATE
        -Wall -Wextra -Werror
        -fvisibility=hidden
        )





#add_executable(shared_library main.cpp AirportFlights.cpp AirportFlights.h Flight.cpp Flight.h)
