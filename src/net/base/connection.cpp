#include "net/base/connection.hpp"
#include "net/base/basic_socket.hpp"

namespace net {
    
Connection::Connection() :
    socket_()
{}

Connection::Connection(StreamSocket &&sock) :
    socket_(std::move(sock))
{}

Connection::~Connection() {
    close();
}

Connection::Connection(Connection &&other) {
    socket_ = std::move(other.socket_);

    /* Zero other socket so we couldn`t use it */
    other.socket_ = std::move(StreamSocket());
}

Connection& Connection::operator=(Connection &&other) {
    socket_ = std::move(other.socket_);

    /* Zero other socket so we couldn`t use it */
    other.socket_ = std::move(StreamSocket());

    return *this;
}

void Connection::close() {
    socket_.close();
}

size_t Connection::send(const utils::ConstBuffer &data) {
    return socket_.send(data.data(), data.size());
}

size_t Connection::recv(utils::MutableBuffer &buff) {
    constexpr int BUFF_SIZE = 128;
    char data[BUFF_SIZE];
    size_t len = socket_.recv(data, BUFF_SIZE);

    // TODO: construct buffer from char array
    buff = std::string(data);

    return len;
}

bool Connection::isOpen() const {
    return socket_ == socketState::kOpened;
}

} // namespace net