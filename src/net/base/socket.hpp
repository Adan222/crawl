#ifndef NET_BASE_SOCKET_HPP_
#define NET_BASE_SOCKET_HPP_

#include <iostream>

#include <sys/socket.h>
#include <unistd.h>

#include "net/base/net_types.hpp"

namespace net {

template<int sockType>
class Socket {
    private:
        socketType fd_;

    public:
        Socket();
        ~Socket();
};

using TCPsocket = Socket<SOCK_STREAM>;
using UDPsocket = Socket<SOCK_DGRAM>;

} // namespace net

#endif // NET_BASE_SOCKET_HPP_