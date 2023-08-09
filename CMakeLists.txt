# Project seviye cmake'te linkleme yapma.
# Proje adı
# Version
# CXX Standart
# Module path
# config ve settings.
# src
# test
# install
# package


#-------------------------------------------------------------------------------------------------#
# SHARED WHITE BOARD
#-------------------------------------------------------------------------------------------------#
cmake_minimum_required(VERSION 3.5)

project(SharedWhiteboard)

set(CMAKE_CXX_STANDARD 14)

#-------------------------------------------------------------------------------------------------#
# CMake module Settings (path,list)
#-------------------------------------------------------------------------------------------------#

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMakeModules")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/scripts/CMake")
set(CMAKE_PREFIX_PATH "/usr/local" ${CMAKE_PREFIX_PATH})

#set(CMAKE_PREFIX_PATH "/Users/egeyildirim/Qt/6.6.0/macos")

#-------------------------------------------------------------------------------------------------#
# Config/Settings
#-------------------------------------------------------------------------------------------------#

include(Config)
include(Version)

#-------------------------------------------------------------------------------------------------#
# Source
#-------------------------------------------------------------------------------------------------#

add_subdirectory(src)


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


# Find and include Qt5
find_package(Qt6 COMPONENTS Widgets Core REQUIRED)
if(Qt6_FOUND)
    link_libraries( Qt6::Core Qt6::Widgets)
    include_directories(${Qt6_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "Qt6 not found. Make sure Qt5 is installed and set Qt5_DIR to the appropriate directory.")
endif()

message(STATUS "Qt6_VERSION: ${Qt6_VERSION}")
message(STATUS "Qt6_INCLUDE_DIRS: ${Qt6_INCLUDE_DIRS}")
message(STATUS "Qt6_LIBRARIES: ${Qt6_LIBRARIES}")

