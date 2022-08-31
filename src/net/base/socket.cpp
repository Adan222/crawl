#include "net/base/socket.hpp"
#include <iostream>
#include <sys/socket.h>

namespace net {

template<int sockType>
Socket<sockType>::Socket(const ip::Address &af) :
    fd_(socket(af.GetProtocol(), sockType, 0))
{
    if(fd_ == -1)
        std::cerr << "error: creating socket\n";
}

template<int sockType>
Socket<sockType>::~Socket() {
    close(fd_);
}

template<int sockType>
inline bool Socket<sockType>::error() const {
    return fd_ == -1;
}
} // namespace net