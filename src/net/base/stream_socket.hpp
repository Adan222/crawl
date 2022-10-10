#ifndef NET_BASE_STREAM_SOCKET_HPP_
#define NET_BASE_STREAM_SOCKET_HPP_

#include <cstddef>

#include "net/base/basic_socket.hpp"
#include "net/base/net_types.hpp"
#include "net/base/tcp.hpp"
#include "base/error.hpp"
#include "net/base/error.hpp"
#include "net/base/functions.hpp"

namespace net {

class StreamSocket : 
    public BasicSocket<tcp>
{
    public:
        StreamSocket();
        ~StreamSocket();
        
        /**
         * Create socket from endpoint
         */
        StreamSocket(const tcp::endpoint &end);

        /* We dnon`t want copy of socket */
        StreamSocket(const StreamSocket &other) = delete;
        StreamSocket& operator=(const StreamSocket &other) = delete;

        /* Allow move */
        StreamSocket(StreamSocket &&other);
        StreamSocket& operator=(StreamSocket &&other);

        size_t send(const void *data, size_t len);
        size_t recv(void *data, size_t len);

        /* I don`t know if it`s good practise */
        bool operator==(const socketState state) const;

        friend bool operator==(const StreamSocket &a, const StreamSocket &b);
        friend bool operator!=(const StreamSocket &a, const StreamSocket &b);

        constexpr static StreamSocket closedSocket();
};

} // namespace net

#endif // NET_BASE_STREAM_SOCKET_HPP_BasicSocket::k