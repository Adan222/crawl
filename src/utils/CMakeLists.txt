set(CRAWL_UTILS_SRC
    # buffer/
    ${CMAKE_SOURCE_DIR}/src/utils/buffer/concept.hpp
    ${CMAKE_SOURCE_DIR}/src/utils/buffer/base_buffer.hpp
    ${CMAKE_SOURCE_DIR}/src/utils/buffer/const_buffer.hpp
    ${CMAKE_SOURCE_DIR}/src/utils/buffer/mutable_buffer.hpp
    
    # error/
    ${CMAKE_SOURCE_DIR}/src/utils/error/error.hpp
    ${CMAKE_SOURCE_DIR}/src/utils/error/error.cpp
    ${CMAKE_SOURCE_DIR}/src/utils/error/netdb_category.hpp
    ${CMAKE_SOURCE_DIR}/src/utils/error/netdb_category.cpp
    
    PARENT_SCOPE
)