#ifndef NET_IP_ADDRESS_V4_HPP_
#define NET_IP_ADDRESS_V4_HPP_

#include <iostream>
#include <string>
#include <cstdint>
#include <cstring>

#include "net/base/basic_address.hpp"

namespace net {
namespace ip {

class AddressV4 : public
    BasicAddress
{
    private:
        std::uint32_t addr_;

    public:
        /* Create empty address */
        AddressV4();

        /* Create address from raw int */
        AddressV4(const std::uint32_t addr);

        ~AddressV4();

        std::string toString() const override;
};

} // namespace ip
} // namespace net

#endif