#include "net/base/address_v6.hpp"

namespace net::ip {

AddressV6::AddressV6() :
    BasicAddress()
{
    /* Create empty address */
    std::memset(&addr_, 0, 16);
}

AddressV6::AddressV6(std::uint8_t bytes[16]) : 
    BasicAddress(),
    addr_()
{
    /* Create address from raw bytes */
    std::memcpy(&addr_, bytes, 16);
}

AddressV6::~AddressV6() {}

std::string AddressV6::toString() const {
    /* For now we use system function 
     * to convert bytes to readable address
    */
    struct sockaddr_in6 sa;
    std::memset(&sa, 0, sizeof(sockaddr_in6));
    std::memcpy(&sa.sin6_addr.s6_addr, &addr_, 16);

    char str[INET6_ADDRSTRLEN];
    inet_ntop(AF_INET6, &(sa.sin6_addr), str, INET6_ADDRSTRLEN);

    return str; 
}

} // namespace net::ip
