#ifndef NET_IP_ADDRESS_V6_HPP_
#define NET_IP_ADDRESS_V6_HPP_

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include <cstdint>
#include <cstring>

#include <netinet/in.h>
#include <arpa/inet.h>

#include "net/ip/basic_address.hpp"

namespace net {
namespace ip {

class AddressV6 : public
    BasicAddress
{
    private:
        std::uint8_t addr_[16];

        void CreateEmptyAddr();
        void CopyAddr(std::uint8_t bytes[16]);

    public:
        /* Create empty address */
        AddressV6();

        /* Create address from raw bytes */
        AddressV6(std::uint8_t bytes[16]);

        ~AddressV6();

        std::string toString() const override;
};

} // namespace ip
} // namespace net

#endif