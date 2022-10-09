#ifndef NET_BASE_BASIC_SOCKET_HPP_
#define NET_BASE_BASIC_SOCKET_HPP_

#include <sys/socket.h>
#include <unistd.h>

#include "base/error.hpp"
#include "net/base/error.hpp"
#include "net/base/net_types.hpp"
#include "net/base/basic_endpoint.hpp"
#include "net/base/functions.hpp"

namespace net {

template<class Proto>
class BasicSocket {
    public:
        using protoType = Proto;
        using endpoint = typename protoType::endpoint;

        BasicSocket();
        ~BasicSocket();

        /* We dnon`t want copy of socket */
        BasicSocket(const BasicSocket &other) = delete;
        BasicSocket& operator=(const BasicSocket &other) = delete;

        /* Allow move */
        BasicSocket(BasicSocket &&other);
        BasicSocket& operator=(BasicSocket &&other);

        void open(const endpoint &end);
        void close();

        socketType getFileDescriptor() const;

    protected:
        constexpr static socketType kEmptySocket = -1;

        socketType fd_;
};

} // namespace net

#endif // NET_BASE_BASIC_SOCKET_HPP_