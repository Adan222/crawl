#include "net/base/basic_socket.hpp"
#include "net/base/tcp.hpp"

namespace net {

template<class Proto>
BasicSocket<Proto>::BasicSocket() :
    fd_(socketState::kNotOpen)
{}

template<class Proto>
BasicSocket<Proto>::BasicSocket(BasicSocket &&other) :
    fd_(std::move(other.fd_))
{
    other.fd_ = socketState::kMoved;
}

template<class Proto>
BasicSocket<Proto>::BasicSocket(const endpoint &end) :
    fd_()
{
    error_code ec;
    fd_ = func::socket(end.getProtocol().family(),
        end.getProtocol().sockType(), 
        0,
        ec);
    if(fd_ == -1)
        error::throwError(ec);
}

template<class Proto>
BasicSocket<Proto>& BasicSocket<Proto>::operator=(BasicSocket<Proto> &&other) {
    fd_ = other.fd_;
    other.fd_ = socketState::kMoved;
    return *this;
}

template<class Proto>
bool BasicSocket<Proto>::operator==(const socketState state) const {
    // Socket is opened when it`s greater from 0.
    // socketState is just for ous to use, to examine 
    // current state of socket.
    if(state == socketState::kOpened)
        return (fd_ > 0);
    else
        return fd_ == state;
}

template<class Proto>
BasicSocket<Proto>::~BasicSocket() {
    ::close(fd_);
    fd_ = socketState::kClosed;
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