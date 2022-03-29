set(NET_LIB_NAME net)
set(CRAWL_NET_LIB_SRC 
    socket/socket.hpp
    socket/socket.cpp
    ip/address.hpp
    ip/address.cpp
    ip/address_v4.hpp
    ip/address_v4.cpp
    ip/address_v6.hpp
    ip/address_v6.cpp
    ip/resolver.hpp
    ip/resolver.cpp
)

add_library(${NET_LIB_NAME} ${CRAWL_NET_LIB_SRC})
target_include_directories(${NET_LIB_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src)

target_link_libraries(${PROJECT_NAME} PUBLIC ${NET_LIB_NAME})