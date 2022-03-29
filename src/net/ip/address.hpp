#ifndef NET_IP_ADDRESS_HPP_
#define NET_IP_ADDRESS_HPP_

#include <string>

#include <sys/socket.h>

#include "net/ip/address_v4.hpp"
#include "net/ip/address_v6.hpp"

namespace net {
namespace ip {

class Address {
    private:
        enum addrType { 
            ipv4, ipv6
        } type_;

        AddressV4 addrV4;
        AddressV6 addrV6;

    public:
        Address();

        Address(const AddressV4 &addr);
        Address(const AddressV6 &addr);

        ~Address();

        std::string ToString() const;
        int GetProtocol() const;
};

} // namespace ip
} // namespace net

#endif