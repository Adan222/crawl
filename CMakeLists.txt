cmake_minimum_required(VERSION 3.13)

project(crowl VERSION 0.0.0)

# C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

configure_file( ${CMAKE_SOURCE_DIR}/crawl.hpp.in
                ${CMAKE_SOURCE_DIR}/src/crawl.hpp)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)

include_directories(${PROJECT_NAME} ${CMAKE_SOURCE_DIR})

# find ccache
include(${CMAKE_SOURCE_DIR}/cmake/ccache.cmake)

add_subdirectory(src)