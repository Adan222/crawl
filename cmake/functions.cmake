# 
# This file contain functions for cmake
#

### Build test for given lib name
function(BuildTest LIB_NAME)
    message(STATUS "Builing makefile for: ${LIB_NAME}Lib")

    set(TEST_NAME "${LIB_NAME}_test")
    set(TEST_SRC
        "${TEST_NAME}.cpp"
    )
    
    add_executable(${TEST_NAME} ${TEST_SRC})
    target_include_directories(${TEST_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src)
    target_link_libraries(${TEST_NAME} PUBLIC ${LIB_NAME})
endfunction()
