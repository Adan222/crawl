#ifndef NET_BASE_CONNECTION_HPP_
#define NET_BASE_CONNECTION_HPP_

#include <cstddef>
#include <iostream>

#include "net/base/stream_socket.hpp"
#include "net/base/tcp.hpp"
#include "net/ip/resolver.hpp"
#include "utils/buffer/mutable_buffer.hpp"
#include "utils/buffer/const_buffer.hpp"

namespace net {

// This class represent connection of TCP
// protocol. We use this class to send and 
// recive data through BasicSocketHandler,
// which is parent class.
// This class in the nearest of low level
// socket stuff.
class Connection {
    public:
        using endpoint = tcp::endpoint;

        // Default constructor and destructor
        Connection();

        // Close socket and connection on destruction
        ~Connection();
        
        // Try connect to endpoint. If you can`t connect 
        // to one, print error and try another. If can`t 
        // connect to any endpoint throw exception
        endpoint connect(const tcp::resolver::resoults &res);

        // close connection
        void close();

        // Send data through connection.
        // Data are stored in ConstBuffer 
        size_t send(const utils::ConstBuffer &data);

        // Recive data from connection and return const buffer.
        // As argument, get how much data store in buff 
        size_t recv(utils::MutableBuffer &buff);

    private:
        bool tryConnect(const endpoint &end);

        StreamSocket socket_;
};

} // namespace net

#endif // NET_BASE_CONNECTION_HPP_