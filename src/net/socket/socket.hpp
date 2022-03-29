#ifndef NET_SOCKET_SOCKET_HPP_
#define NET_SOCKET_SOCKET_HPP_

#include <sys/socket.h>

#include "net/ip/address.hpp"

namespace net {

constexpr int kdefaultSocketType = SOCK_STREAM;

class Socket {
    private:
        int fd_;

    public:
        Socket();
        Socket(const ip::Address& addr);
        ~Socket();
};

} // namespace net

#endif 