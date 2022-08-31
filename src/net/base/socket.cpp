#include "net/base/socket.hpp"

namespace net {

template<int sockType>
Socket<sockType>::Socket() {}

template<int sockType>
Socket<sockType>::~Socket() {}

template<int sockType>
inline bool Socket<sockType>::error() const {
    return fd_ == -1;
}
} // namespace net