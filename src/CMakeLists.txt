set(CRAWL_SRC
    main.cpp
)

add_executable(${PROJECT_NAME}
    ${CRAWL_SRC}
)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src)

add_subdirectory(net)
add_subdirectory(crypto)
