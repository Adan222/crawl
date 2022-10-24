set(CRAWL_NET_SRC
    # base
    net/base/basic_socket.hpp
    net/base/basic_socket.cpp
    net/base/tcp.hpp
    net/base/tcp.cpp
    net/base/net_types.hpp
    net/base/basic_endpoint.hpp
    net/base/basic_endpoint.cpp
    net/base/error.hpp
    net/base/connection.hpp
    net/base/connection.cpp
    net/base/functions.hpp
    net/base/functions.cpp
    net/base/stream_socket.hpp
    net/base/stream_socket.cpp
    net/base/connect.hpp
    net/base/connect.cpp

    #ip
    net/ip/address.hpp
    net/ip/address.cpp
    net/ip/address_v4.hpp
    net/ip/address_v4.cpp
    net/ip/address_v6.hpp
    net/ip/address_v6.cpp
    net/ip/resolver.hpp
    net/ip/resolver.cpp
    net/ip/basic_query.hpp
    #net/ip/basic_query.cpp
    net/ip/basic_resoults.hpp
    net/ip/basic_resoults.cpp
    net/ip/basic_resoults_iterator.hpp
    net/ip/basic_resoults_iterator.cpp

    PARENT_SCOPE
)
