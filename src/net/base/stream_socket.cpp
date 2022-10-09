#include "net/base/stream_socket.hpp"
#include "net/base/basic_socket.hpp"
#include <utility>

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

} // namespace net