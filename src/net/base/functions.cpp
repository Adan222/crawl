#include "net/base/functions.hpp"
#include "utils/error/error.hpp"
#include "utils/error/netdb_category.hpp"

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
    int ret = ::connect(sockfd, addr, addrlen);
    error::getLastError(e);
    
    return ret;
}

size_t recv(int sockfd, void *buf, size_t len, int flags, net::error_code &e) {
    const auto ret = ::recv(sockfd, buf, len, flags);    
    error::getLastError(e);

    return ret;
}

int getaddrinfo(const char *node, const char *service,
    const struct addrinfo *hints,
    struct addrinfo **res,
    net::error_code &e)
{
    int ret = getaddrinfo(node, service, hints, res);

    if(ret < 0)
        e = error::make_error_code(static_cast<error::netdb_errc>(ret));
    
    return ret;
}

} // namespace net::func