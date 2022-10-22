#include "net/ip/address_v6.hpp"
#include "net/base/net_types.hpp"

namespace net::ip {

AddressV6::AddressV6() :
    addr_(),
    scope_(0)
{
    /* Create empty address */
    ::memset(&addr_, 0, 16);
}

AddressV6::AddressV6(const v6ByteArray &bytes, scope_id_type scope) :
    addr_(),
    scope_(scope)
{
    /* Create address from raw bytes */
    ::memcpy(&addr_, &bytes, 16);
}

AddressV6::AddressV6(const v6ByteType &bytes, scope_id_type scope) :
    addr_(),
    scope_(scope)
{
    ::memcpy(&addr_, &bytes, 16);
}

AddressV6::~AddressV6() {}

std::string AddressV6::toString() const {
    char str[INET6_ADDRSTRLEN];
    ::inet_ntop(AF_INET6, &addr_, str, INET6_ADDRSTRLEN);

    return str; 
}

AddressV6::v6ByteArray AddressV6::toBytes() const {
    v6ByteArray byte;
    ::memcpy(byte.data(), addr_.s6_addr, 16);

    return byte;
}

scope_id_type AddressV6::getScope() const {
    return scope_;
}

bool operator==(const AddressV6 &a, const AddressV6 &b) {
    return (::memcmp(&a.addr_, &b.addr_, sizeof(in6_addr_type)) == 0);
}

bool operator!=(const AddressV6 &a, const AddressV6 &b) {
    return !(a == b);
}

namespace V6 {

AddressV6 fromString(const std::string &str) {
    return fromString(str.c_str());
}

AddressV6 fromString(const char *str) {
    AddressV6::v6ByteArray addr;
    ::inet_pton(AF_INET6, str, addr.data());
    
    return AddressV6(addr, 0);
}

} // namespace V6

} // namespace net::ip
