#include "net/base/stream_socket.hpp"

namespace net {
StreamSocket::StreamSocket() :
    BasicSocket<tcp>()
{}

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