#include "net/base/socket.hpp"
#include <iostream>
#include <sys/socket.h>

namespace net {

template<int sockType>
Socket<sockType>::Socket() {}

template<int sockType>
Socket<sockType>::~Socket() {
    close(fd_);
}

} // namespace net