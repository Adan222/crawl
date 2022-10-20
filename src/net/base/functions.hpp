#ifndef NET_BASE_FUNCTIONS_HPP_
#define NET_BASE_FUNCTIONS_HPP_

#include <cstddef>

#include "utils/error/error.hpp"
#include "net/base/error.hpp"
#include "net/base/net_types.hpp"

namespace net::func {

socketType socket(int domain, int type, int protocol, net::error_code &e);
int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen, net::error_code &e);
size_t send(int sockfd, const void *buf, size_t len, int flags, net::error_code &e);
size_t recv(int sockfd, void *buf, size_t len, int flags, net::error_code &e);

int getaddrinfo(const char *node, const char *service,
    const struct addrinfo *hints,
    struct addrinfo **res,
    net::error_code &e);

} // namespace net::func

#endif // NET_BASE_FUNCTIONS_HPP_