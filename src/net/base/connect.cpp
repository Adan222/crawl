#include "net/base/connect.hpp"

namespace net {

int connSocket
    (const StreamSocket &sock, const tcp::endpoint &end)
{
    net::error_code ec;
    socklen_type len = end.isV4() ? 
        sizeof(sockaddr_v4_type) : sizeof(sockaddr_v6_type);

    return func::connect(sock.getFileDescriptor(),
        end.getData(),
        len,
        ec);
}

std::unique_ptr<Connection> connect(const tcp::resolver::resoults &res) {
    auto conn = std::make_unique<Connection>();
    for(const auto &i : res) {
        // If error occured, just go to the next iteration
        try{
            // Create apropriate socket and try to connect
            StreamSocket sock(i);
            int ret = connSocket(sock, i);

            // If we get error while we establish connection,
            // this assignment won`t execute
            *conn = std::move(sock);
        }
        catch(const std::exception &e) {
            std::cerr << e.what() << "\n";
        }
    }

    //const std::string hostName = res[0].getHostName();
    if(!conn->isOpen())
        throw std::runtime_error("Can`t connect to: ");

    return std::move(conn);
}

} // namespace net
