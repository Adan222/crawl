set(CRAWL_SRC
    main.cpp
)

add_executable(${PROJECT_NAME}
    ${CRAWL_SRC}
)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src)

# all external libs here:

# I think this could be done better,
# for example we can fetch source code to src/crypto
# I also know that cryptopp is available as distro package
# so, we can check if it`s installed and if not,
# then download it from repo, so...
# TODO: cmake crypto++

include(FetchContent)
FetchContent_Declare(
    cryptopp
    GIT_REPOSITORY https://github.com/abdes/cryptopp-cmake.git
)
set(BUILD_TESTING OFF)
FetchContent_MakeAvailable(cryptopp)

target_link_libraries(${PROJECT_NAME} PUBLIC cryptopp)
target_include_directories(${PROJECT_NAME} PUBLIC cryptopp)

add_subdirectory(net)
