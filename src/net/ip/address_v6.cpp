#include "net/ip/address_v6.hpp"
#include <cstring>

namespace net::ip {

AddressV6::AddressV6() {
    /* Create empty address */
    ::memset(&addr_, 0, 16);
}

AddressV6::AddressV6(const v6ByteType &bytes) {
    /* Create address from raw bytes */
    ::memcpy(&addr_, &bytes, 16);
}

AddressV6::~AddressV6() {}

std::string AddressV6::toString() const {
    char str[INET6_ADDRSTRLEN];
    ::inet_ntop(AF_INET6, &addr_, str, INET6_ADDRSTRLEN);

    return str; 
}

AddressV6::v6ByteType AddressV6::toBytes() const {
    v6ByteType byte;
    ::memcpy(byte.data(), addr_.s6_addr, 16);

    return byte;
}

namespace V6 {

AddressV6 fromString(const std::string &str) {
    return fromString(str.c_str());
}

AddressV6 fromString(const char *str) {
    AddressV6::v6ByteType addr;
    ::inet_pton(AF_INET6, str, addr.data());

    return AddressV6(addr);
}

} // namespace V6

} // namespace net::ip
