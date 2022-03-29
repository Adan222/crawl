#ifndef NET_IP_RESOLVER_HPP_
#define NET_IP_RESOLVER_HPP_

#include <string>
#include <vector>

#include <cstring>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#include "net/ip/address.hpp"

namespace net {
namespace ip {

typedef std::vector<Address> AddressList;

class Resolver {
    private:
        struct addrinfo hint_;

        void CreateHint();
    public:
        Resolver();
        ~Resolver();

        AddressList Resolve(const std::string &domain);
};

} // namespace ip
} // namespace net

#endif