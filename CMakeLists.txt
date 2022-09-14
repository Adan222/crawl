cmake_minimum_required(VERSION 3.24)

project(crawl VERSION 0.0.0)

# C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

configure_file( ${CMAKE_SOURCE_DIR}/config.hpp.in
                ${CMAKE_SOURCE_DIR}/src/base/config.hpp)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)

include_directories(${PROJECT_NAME} ${CMAKE_SOURCE_DIR})

# cmake include path:
set(CRAWL_CMAKE_INCLUDE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# all includes
include(${CRAWL_CMAKE_INCLUDE_PATH}/ccache.cmake)

add_subdirectory(src)