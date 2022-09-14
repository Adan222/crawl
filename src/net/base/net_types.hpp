#ifndef NET_BASE_NET_TYPES_HPP_
#define NET_BASE_NET_TYPES_HPP_

#include <system_error>

#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

namespace net {

typedef int socketType;
typedef unsigned short portType;

typedef in_addr in4_addr_type;
typedef in6_addr in6_addr_type;
typedef sockaddr sockaddr_type;
typedef sockaddr_in sockaddr_v4_type;
typedef sockaddr_in6 sockaddr_v6_type;

} // namespace net


#endif // NET_BASE_NET_TYPES_HPP_