#ifndef NET_BASE_STREAM_SOCKET_HPP_
#define NET_BASE_STREAM_SOCKET_HPP_

#include <cstddef>

#include "net/base/basic_socket.hpp"
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

        size_t send(const void *data, size_t len);
        size_t recv(void *data, size_t len);
};

} // namespace net

#endif // NET_BASE_STREAM_SOCKET_HPP_