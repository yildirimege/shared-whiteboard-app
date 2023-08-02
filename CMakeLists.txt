cmake_minimum_required(VERSION 3.5)

project(SharedWhiteboard)

set(CMAKE_CXX_STANDARD 11)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMakeModules")


# Find and include SFML
find_package(SFML COMPONENTS graphics REQUIRED)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "SFML not found. Make sure SFML is installed and set SFML_ROOT to the appropriate directory.")
endif()


# Find and include Boost.Asio
find_package(Boost REQUIRED COMPONENTS system)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "Boost not found. Make sure Boost is installed and set BOOST_ROOT to the appropriate directory.")
endif()

add_subdirectory(lib)
add_subdirectory(app)