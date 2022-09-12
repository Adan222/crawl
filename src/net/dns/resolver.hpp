#ifndef NET_IP_RESOLVER_HPP_
#define NET_IP_RESOLVER_HPP_

#include <string>
#include <vector>

#include <cstring>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#include "net/ip/address.hpp"

namespace net::ip {

typedef std::vector<Address> AddressList;

class Resolver {
    private:
        struct addrinfo hint_;

        void CreateHint();
    public:
        Resolver();
        ~Resolver();

        AddressList resolve(const std::string &domain);
};

} // namespace net::ip

#endif