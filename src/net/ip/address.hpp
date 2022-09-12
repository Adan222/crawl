#ifndef NET_IP_ADDRESS_HPP_
#define NET_IP_ADDRESS_HPP_

#include <netdb.h>
#include <string>

#include <sys/socket.h>

#include "net/ip/address_v4.hpp"
#include "net/ip/address_v6.hpp"

namespace net::ip {

// This class represent both address type so we
// can use only one class in connections etc.
class Address {
    private:
        enum addrType 
            { ipv4, ipv6 } type_;

        AddressV4 v4;
        AddressV6 v6;

    public:
        Address();
        Address(const AddressV4 &addr);
        Address(const AddressV6 &addr);

        ~Address();

        bool isV4() const;
        bool isV6() const;

        std::string toString() const;
};

} // namespace net::ip

#endif