#include "net/base/functions.hpp"
#include "base/error.hpp"
#include <cstddef>
#include <sys/socket.h>

namespace net::func {

socketType socket(int domain, int type, int protocol, net::error_code &e) {
    socketType fd = ::socket(domain, type, protocol);
    error::getLastError(e);

    return fd;
}

size_t send(int sockfd, const void *buf, size_t len, int flags, net::error_code &e) {
    size_t ret = ::send(sockfd, buf, len, flags);
    error::getLastError(e);

    return ret;
}

int connect(int sockfd, const struct sockaddr *addr,
     socklen_t addrlen, net::error_code &e) 
{
    int ret = connect(sockfd, addr, addrlen);
    error::getLastError(e);

    if(ret == -1)
        error::throwError(e);
    
    return ret;
}

size_t recv(int sockfd, void *buf, size_t len, int flags, net::error_code &e) {
    size_t ret = ::recv(sockfd, buf, len, flags);    
    error::getLastError(e);

    return ret;
}


} // namespace net::func