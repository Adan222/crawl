#ifndef NET_IP_ADDRESS_V6_HPP_
#define NET_IP_ADDRESS_V6_HPP_

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <array>

#include <cstdint>
#include <cstring>

#include <netinet/in.h>
#include <arpa/inet.h>

#include "net/base/basic_address.hpp"

namespace net::ip {

using Addr6Literal = std::array<std::uint8_t, 16>;

class AddressV6 : public
    BasicAddress
{
    private:
        Addr6Literal addr_;

    public:
        /* Create empty address */
        AddressV6();

        /* Create address from raw bytes */
        AddressV6(std::uint8_t bytes[16]);

        ~AddressV6();

        std::string toString() const override;
};

} // namespace net::ip

#endif