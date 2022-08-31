#ifndef NET_IP_ADDRESS_V4_HPP_
#define NET_IP_ADDRESS_V4_HPP_

#include <iostream>
#include <string>
#include <cstdint>
#include <cstring>

#include "net/base/basic_address.hpp"

namespace net::ip {

using AddrLiteral = std::uint32_t;

class AddressV4 : public
    BasicAddress
{
    private:
        AddrLiteral addr_;

    public:
        /* Create empty address */
        AddressV4();

        /* Create address from raw int */
        AddressV4(const AddrLiteral addr);

        ~AddressV4();

        std::string toString() const override;
};

} // namespace net::ip

#endif