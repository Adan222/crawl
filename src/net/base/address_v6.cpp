#include "net/ip/address_v6.hpp"
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <string>

namespace net {
namespace ip {

AddressV6::AddressV6() :
    BasicAddress()
{
    CreateEmptyAddr();
}

AddressV6::AddressV6(std::uint8_t bytes[16]) : 
    BasicAddress(),
    addr_()
{
    CopyAddr(bytes);
}

AddressV6::~AddressV6() {}

void AddressV6::CreateEmptyAddr() {
    std::memset(addr_, 0, 16);
}

void AddressV6::CopyAddr(std::uint8_t bytes[16]) {
    std::memcpy(addr_, bytes, 16);
}

std::string AddressV6::toString() const {
    /* For now we use system function 
     * to convert bytes to readable address
    */
    struct sockaddr_in6 sa;
    std::memset(&sa, 0, sizeof(sockaddr_in6));
    std::memcpy(&sa.sin6_addr.s6_addr, addr_, 16);

    char str[INET6_ADDRSTRLEN];
    inet_ntop(AF_INET6, &(sa.sin6_addr), str, INET6_ADDRSTRLEN);

    return str; 
}

} // namespace ip
} // namespace net
