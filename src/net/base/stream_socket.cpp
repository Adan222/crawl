#include "net/base/stream_socket.hpp"
#include "net/base/basic_socket.hpp"

namespace net {
StreamSocket::StreamSocket() :
    BasicSocket<tcp>()
{}

StreamSocket::StreamSocket(StreamSocket &&other) :
    BasicSocket(std::move(other))
{}

StreamSocket& StreamSocket::operator=(StreamSocket &&other) {
    BasicSocket::operator=(std::move(other));
    return *this;
}

StreamSocket::~StreamSocket() {}

StreamSocket::StreamSocket(const tcp::endpoint &end) :
    BasicSocket(end)
{}

size_t StreamSocket::send(const void *data, size_t len) {
    error_code ec;
    size_t ret = func::send(fd_, data, len, 0, ec);

    if(ret == -1)
        error::throwError(ec);
    return  ret;
}

size_t StreamSocket::recv(void *data, size_t len) {
    error_code ec;
    auto ret = func::recv(fd_, data, len, 0, ec);

    if(ret == -1)
        error::throwError(ec);
    return  ret;
}

bool StreamSocket::operator==(const socketState state) const {
    return BasicSocket::operator==(state);
}

bool operator==(const StreamSocket &a, const StreamSocket &b) {
    return a.fd_ == b.fd_;
}

bool operator!=(const StreamSocket &a, const StreamSocket &b) {
    return !(a == b);
}

} // namespace net
