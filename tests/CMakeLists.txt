message(STATUS "Looking for: Catch2")
find_package(Catch2 QUIET)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# If we didn`t found Catch2, download 
# it from github
if(NOT Catch2_FOUND)
    set(CRAWL_CATCH2_GITHUB_PATH https://github.com/catchorg/Catch2.git)

    # TODO: Better messages here
    message(STATUS "Catch2 didn`t found")
    message(STATUS "Downloading Catch2 from: ${CRAWL_CATCH2_GITHUB_PATH}")
    Include(FetchContent)

    set(BUILD_TESTING OFF)

    FetchContent_Declare(
        Catch2
        GIT_REPOSITORY ${CRAWL_CATCH2_GITHUB_PATH}
        GIT_TAG        v3.0.1 # or a later release
    )
    message(STATUS "Downloaded to: ${Catch2_SOURCE_DIR}")

    FetchContent_MakeAvailable(Catch2)

else()
    message(STATUS "Catch2 found")
endif()

# all subdirs here
add_subdirectory(net)

set(CRAWL_TEST_SRC
    main.cpp
    mem_dump.hpp
    mem_dump.cpp

    ${CRAWL_TEST_NET_SRC}
)

add_executable(crawl_test ${CRAWL_TEST_SRC})

# main src
target_include_directories(crawl_test PUBLIC ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(crawl_test PUBLIC crawl_src)

# catch2
target_link_libraries(crawl_test PUBLIC Catch2::Catch2)
target_include_directories(crawl_test PUBLIC Catch2::Catch2)
