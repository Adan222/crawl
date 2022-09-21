#ifndef NET_BASE_CONNECTION_HPP_
#define NET_BASE_CONNECTION_HPP_

#include <iostream>

#include "net/base/stream_socket.hpp"
#include "net/base/tcp.hpp"
#include "net/ip/resolver.hpp"

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
        using Buffer = void*;

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

        // TODO: Make special class for data storage
        // Instead of void* here, there will be special
        // class called Buffer.
        size_t send(Buffer data);
        size_t recv(Buffer data);

    private:
        bool tryConnect(const endpoint &end);

        StreamSocket socket_;
};

} // namespace net

#endif // NET_BASE_CONNECTION_HPP_