#ifndef NET_BASE_SOCKET_HPP_
#define NET_BASE_SOCKET_HPP_

#include <iostream>

#include <sys/socket.h>

namespace net {

template<int sockType>
class Socket {
    private:
        int fd_;

    public:
        Socket();
        ~Socket();

        inline bool error() const;
};

using TCPsocket = Socket<SOCK_STREAM>;
using UDPsocket = Socket<SOCK_DGRAM>;

} // namespace net

#endif // NET_BASE_SOCKET_HPP_