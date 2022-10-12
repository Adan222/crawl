set(CRAWL_NET_SRC
    # base
    ${CMAKE_SOURCE_DIR}/src/net/base/basic_socket.hpp
    ${CMAKE_SOURCE_DIR}/src/net/base/basic_socket.cpp
    ${CMAKE_SOURCE_DIR}/src/net/base/tcp.hpp
    ${CMAKE_SOURCE_DIR}/src/net/base/tcp.cpp
    ${CMAKE_SOURCE_DIR}/src/net/base/net_types.hpp
    ${CMAKE_SOURCE_DIR}/src/net/base/basic_endpoint.hpp
    ${CMAKE_SOURCE_DIR}/src/net/base/basic_endpoint.cpp
    ${CMAKE_SOURCE_DIR}/src/net/base/error.hpp
    ${CMAKE_SOURCE_DIR}/src/net/base/connection.hpp
    ${CMAKE_SOURCE_DIR}/src/net/base/connection.cpp
    ${CMAKE_SOURCE_DIR}/src/net/base/functions.hpp
    ${CMAKE_SOURCE_DIR}/src/net/base/functions.cpp
    ${CMAKE_SOURCE_DIR}/src/net/base/stream_socket.hpp
    ${CMAKE_SOURCE_DIR}/src/net/base/stream_socket.cpp
    ${CMAKE_SOURCE_DIR}/src/net/base/connect.hpp
    ${CMAKE_SOURCE_DIR}/src/net/base/connect.cpp

    #ip
    ${CMAKE_SOURCE_DIR}/src/net/ip/address.hpp
    ${CMAKE_SOURCE_DIR}/src/net/ip/address.cpp
    ${CMAKE_SOURCE_DIR}/src/net/ip/address_v4.hpp
    ${CMAKE_SOURCE_DIR}/src/net/ip/address_v4.cpp
    ${CMAKE_SOURCE_DIR}/src/net/ip/address_v6.hpp
    ${CMAKE_SOURCE_DIR}/src/net/ip/address_v6.cpp
    ${CMAKE_SOURCE_DIR}/src/net/ip/resolver.hpp
    ${CMAKE_SOURCE_DIR}/src/net/ip/resolver.cpp
    ${CMAKE_SOURCE_DIR}/src/net/ip/basic_query.hpp
    ${CMAKE_SOURCE_DIR}/src/net/ip/basic_query.cpp
    ${CMAKE_SOURCE_DIR}/src/net/ip/basic_resoults.hpp
    ${CMAKE_SOURCE_DIR}/src/net/ip/basic_resoults.cpp
    ${CMAKE_SOURCE_DIR}/src/net/ip/basic_resoults_iterator.hpp
    ${CMAKE_SOURCE_DIR}/src/net/ip/basic_resoults_iterator.cpp

    PARENT_SCOPE
)
