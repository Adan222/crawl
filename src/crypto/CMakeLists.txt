include(${CRAWL_CMAKE_INCLUDE_PATH}/lib_include.cmake)

set(CRYPTO_LIB_NAME crypto)
set(CRYPTO_LIB_SRC
    math/big_int.hpp
    math/big_int.cpp
)

add_library(${CRYPTO_LIB_NAME} ${CRYPTO_LIB_SRC})
target_include_directories(${CRYPTO_LIB_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src)

target_link_libraries(${PROJECT_NAME} PUBLIC ${CRYPTO_LIB_NAME})

if(${TEST_BUILD_CRYPTO_LIB_TEST})
    BuildTest(${CRYPTO_LIB_NAME})
endif()