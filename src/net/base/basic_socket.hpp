#ifndef NET_BASE_SOCKET_HPP_
#define NET_BASE_SOCKET_HPP_

#include <iostream>

#include <sys/socket.h>
#include <unistd.h>

#include "base/error.hpp"
#include "net/base/net_types.hpp"

namespace net {

template<class Proto>
class BasicSocket {
    public:
        typedef Proto protoType;

        BasicSocket();
        ~BasicSocket();

        void open();
        void close();

    private:
        socketType fd_;
};

} // namespace net

#endif // NET_BASE_SOCKET_HPP_