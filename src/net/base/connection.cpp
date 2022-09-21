#include "net/base/connection.hpp"
#include "net/base/net_types.hpp"

namespace net {
Connection::Connection() :
    socket_()
{}

Connection::~Connection() {
    close();
}

typename Connection::endpoint 
    Connection::connect(const tcp::resolver::resoults &res) 
{
    // Create socket and try each endpoint to connect,
    // then print message.
    for(const auto &i : res) {
        socket_.open(i);

        std::cout << "= Trying connect to " <<
            i.getAddress().toString() << "\n";

        if(tryConnect(i)) {
            // TODO: Make logger
            std::cout << "== Connected to " <<
                i.getAddress().toString() << "\n";
            return i;
        }
        else {
            std::cout << "== Can`t connect to " <<
                i.getAddress().toString() << "\n";
        }
    }
    return endpoint(); 
}

void Connection::close() {
    socket_.close();
}

size_t Connection::send(Buffer data) {
    return socket_.send(data, 0);
}

size_t Connection::recv(Buffer data) {
    return socket_.recv(data, 0);
}

bool Connection::tryConnect(const endpoint &end) 
{
    error_code ec;

    // len of sockaddr required to connect
    int len = end.isV4() ? 
        sizeof(sockaddr_v4_type) : sizeof(sockaddr_v6_type);

    try {
        // return value of connect
        int ret = func::connect(socket_.getFileDescriptor(), 
            end.getData(), 
            len, 
            ec);

    } catch (const std::exception& e) {
        // If we catch error then close socket
        // return false. In connect() function 
        // we print error that we can`t connect
        // to, and try another endpoint.

        socket_.close();
        return false;
    }
    return true;
}


} // namespace net