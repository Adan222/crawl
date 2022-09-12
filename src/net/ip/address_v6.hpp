#ifndef NET_BASE_ADDRESS_V6_HPP_
#define NET_BASE_ADDRESS_V6_HPP_

#include <iostream>
#include <string>
#include <array>

#include <cstring>

#include <netinet/in.h>
#include <arpa/inet.h>

#include "net/base/net_types.hpp"

namespace net::ip {

// This class represent ipv6 address
class AddressV6 {
    public:
        using v6ByteType = std::array<std::uint8_t, 16>;

        /* Create empty address */
        AddressV6();

        /* Create address from raw bytes */
        AddressV6(const v6ByteType &bytes);

        ~AddressV6();

        std::string toString() const;

    private:
        in6_addr_type addr_;
};

namespace V6 {
    AddressV6 fromString(const std::string &str);
    AddressV6 fromString(const char *str);
}


} // namespace net::ip

#endif