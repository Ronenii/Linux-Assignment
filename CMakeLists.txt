cmake_minimum_required(VERSION 3.13)  # CMake version check
project(linux-assignment VERSION 1.0)     # Create project
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)              # Enable c++20 standard

#find_library(ZIPLIB zip)

#add custom lib
add_subdirectory(lib)

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES src/main.cpp)

#add all src files
#file(GLOB_RECURSE SRC_FILES src/*.cpp)
file(GLOB SRC_FILES CONFIGURE_DEPENDS "src/programs.cpp")

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(linux-assignment ${SOURCE_FILES} ${SRC_FILES})

target_link_libraries(linux-assignment PUBLIC lib)
#target_link_libraries(runMe PUBLIC ${ZIPLIB})
target_link_libraries(linux-assignment PUBLIC "/usr/local/lib/libzip.so")


target_include_directories(linux-assignment PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/src/"
        "${CMAKE_CURRENT_SOURCE_DIR}/lib/"
        "/usr/local/include/"
        )