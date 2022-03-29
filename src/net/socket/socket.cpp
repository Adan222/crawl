#include "net/socket/socket.hpp"
#include <sys/socket.h>

namespace net {

Socket::Socket() {}

Socket::Socket(const ip::Address& addr) : 
    fd_(socket(addr.GetProtocol(), kdefaultSocketType, 0))
{}

Socket::~Socket() {}

} // namespace net