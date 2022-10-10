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

/* 
 * Wikipedia said:
 *     "File descriptors typically have non-negative integer values, 
 *     with negative values being reserved to indicate "no value" 
 *     or error conditions."
 *
 * So we can do assume that values bellow -1 are free to use.
*/
enum socketState {
    kError = -1,
    kNotOpen = -2,
    kOpened = -3,
    kClosed = -4,
    kMoved = -5
};

/**
 * Base class for any type of sockets
 */
template<class Proto>
class BasicSocket {
    public:
        using protoType = Proto;
        using endpoint = typename protoType::endpoint;

        /**
         * Default constructor
         *
         * Create empty socket, but do we need
         * empty socket?
         */
        BasicSocket();

        /**
         * Create socket which will fit with endpoint
         *
         * @param end based on this endpoint we want to create socket
         */
        BasicSocket(const endpoint &end);
        ~BasicSocket();

        /* We don`t want copy of socket */
        BasicSocket(const BasicSocket &other) = delete;
        BasicSocket& operator=(const BasicSocket &other) = delete;

        /* Allow move */
        BasicSocket(BasicSocket &&other);
        BasicSocket& operator=(BasicSocket &&other);

        /**
         * Check state
         *
         * I don`t know if it`s good practice.
         *
         * @param state state of the socket
         * @return if socket state is equal with given state. 
         */
        bool operator==(const socketState state) const;

        /* close file descriptor */
        void close();

        socketType getFileDescriptor() const;

    protected:
        socketType fd_;
};

} // namespace net

#endif // NET_BASE_BASIC_SOCKET_HPP_