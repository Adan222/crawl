#ifndef NET_BASE_SOCKET_HPP_
#define NET_BASE_SOCKET_HPP_

#include "net/base/address.hpp"
#include <iostream>

#include <sys/socket.h>
#include <unistd.h>

namespace net {

template<int sockType>
class Socket {
    private:
        int fd_;

    public:
        Socket() = delete;
        Socket(const ip::Address &af);
        ~Socket();

        inline bool error() const;
};

using TCPsocket = Socket<SOCK_STREAM>;
using UDPsocket = Socket<SOCK_DGRAM>;

} // namespace net

#endif // NET_BASE_SOCKET_HPP_