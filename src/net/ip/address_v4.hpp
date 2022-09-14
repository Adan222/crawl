#ifndef NET_IP_ADDRESS_V4_HPP_
#define NET_IP_ADDRESS_V4_HPP_

#include <array>
#include <string>
#include <cstring>

#include <arpa/inet.h>

#include "net/base/net_types.hpp"

namespace net::ip {

// This class represent ipv4 address
class AddressV4 {
    public:
        using v4Type = std::uint32_t;
        using v4ByteType = std::array<std::uint8_t, 4>;

        /* Create empty address */
        AddressV4();

        /* Create address from raw int and bytes */
        AddressV4(const v4Type addr);
        AddressV4(const v4ByteType &bytes);

        ~AddressV4();

        std::string toString() const;
        v4Type toInt() const;

    private:
        in4_addr_type addr_;
};

namespace V4 {

    AddressV4 fromString(const std::string &str);
    AddressV4 fromString(const char *str);

} // namespace V4

} // namespace net::ip

#endif