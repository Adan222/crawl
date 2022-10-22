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

// Forward declaraion 
class AddressV6;

// Friend functions
bool operator==(const AddressV6 &a, const AddressV6 &b);
bool operator!=(const AddressV6 &a, const AddressV6 &b);

// This class represent ipv6 address
class AddressV6 {
    public:
        using v6ByteArray = std::array<std::uint8_t, 16>;
        using v6ByteType = std::uint8_t[16];

        /* Create empty address */
        AddressV6();

        /* Create address from raw bytes */
        AddressV6(const v6ByteArray &bytes, scope_id_type scope);
        AddressV6(const v6ByteType &bytes, scope_id_type scope);

        ~AddressV6();

        std::string toString() const;
        v6ByteArray toBytes() const;

        scope_id_type getScope() const;

        friend bool operator==(const AddressV6 &a, const AddressV6 &b);
        friend bool operator!=(const AddressV6 &a, const AddressV6 &b);

    private:
        in6_addr_type addr_;
        scope_id_type scope_;
};

namespace V6 {
    /**
     * Create AddressV6 from string
     *
     * @return AddressV6 object
     */
    AddressV6 fromString(const std::string &str);
    AddressV6 fromString(const char *str);
}

} // namespace net::ip

#endif