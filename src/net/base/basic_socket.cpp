#include "net/base/basic_socket.hpp"
#include "net/base/tcp.hpp"

namespace net {
using error::throwError;

template<class Proto>
BasicSocket<Proto>::BasicSocket() {}

template<class Proto>
BasicSocket<Proto>::~BasicSocket() {
    ::close(fd_);
}

template<class Proto>
void BasicSocket<Proto>::open(const endpoint &end) {
    error_code ec;
    fd_ = func::socket(end.getProtocol().family(),
        end.getProtocol().sockType(), 
        0,
        ec);
    if(fd_ == -1)
      throwError(ec);
}

template<class Proto>
void BasicSocket<Proto>::close() {
    ::close(fd_);
}

template<class Proto>
socketType BasicSocket<Proto>::getFileDescriptor() const {
    return fd_;
}

template class BasicSocket<tcp>;

} // namespace net