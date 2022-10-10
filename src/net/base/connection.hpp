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

/** 
 * This class represent connection of TCP protocol.
 *
 * We use this class to send and recive
 * data through BasicSocketHandler, which is parent class.
 * This class in the nearest of low level
 * socket stuff.
 */
class Connection {
    public:
        using endpoint = tcp::endpoint;

        /* Default constructor and destructor */
        Connection();

        /**
         * Construct from socket
         */
        Connection(StreamSocket &&sock);

        /** 
         * Delate copying
         * 
         * We want only one object of each connection.
         */
        Connection(const Connection &other) = delete;
        Connection& operator=(const Connection &other) = delete;

        /* Moving allowed */
        Connection(Connection &&other);
        Connection& operator=(Connection &&other);

        /* Close socket and connection on destruction */
        ~Connection();
        
        /* Close connection */
        void close();

        /** Send data through connection.
         *
         * @param &data buffer with data to send
         * @return Size of sended data
         */
        size_t send(const utils::ConstBuffer &data);

        /**
         * Recive data from connection and return const buffer.
         * 
         * @param  buff  buffer where we put recived data
         * @return Size of recived data 
         */
        size_t recv(utils::MutableBuffer &buff);

        /**
         * Check if connection is opened
         *
         * If socket is opened and is valid, then connection
         * is also opened.
         */
        bool isOpen() const;

    private:
        StreamSocket socket_;
        endpoint end_; 
};

} // namespace net

#endif // NET_BASE_CONNECTION_HPP_