#include "net/base/basic_socket.hpp"
#include "net/base/tcp.hpp"

namespace net {

template<class Proto>
BasicSocket<Proto>::BasicSocket() :
    fd_(kEmptySocket)
{}

template<class Proto>
BasicSocket<Proto>::BasicSocket(BasicSocket &&other) :
    fd_(std::move(other.fd_))
{
    other.fd_ = kEmptySocket;
}

template<class Proto>
BasicSocket<Proto>& BasicSocket<Proto>::operator=(BasicSocket<Proto> &&other) {
    fd_ = other.fd_;
    other.fd_ = kEmptySocket;
    return *this;
}

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
        error::throwError(ec);
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