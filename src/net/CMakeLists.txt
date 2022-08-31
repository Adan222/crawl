set(NET_LIB_NAME net)
set(NET_LIB_SRC 
    base/socket.hpp
    base/socket.cpp
    base/address.hpp
    base/address.cpp
    base/address_v4.hpp
    base/address_v4.cpp
    base/address_v6.hpp
    base/address_v6.cpp
    base/resolver.hpp
    base/resolver.cpp
)

add_library(${NET_LIB_NAME} ${NET_LIB_SRC})
target_include_directories(${NET_LIB_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src)

target_link_libraries(${PROJECT_NAME} PUBLIC ${NET_LIB_NAME})