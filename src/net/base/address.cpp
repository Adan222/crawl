#include "net/base/address.hpp"

namespace net::ip {

Address::Address() :
    type_()
{}

Address::Address(const AddressV4 &addr) : 
    type_(addrType::ipv4),
    addrV4(addr)
{}

Address::Address(const AddressV6 &addr): 
    type_(addrType::ipv6),
    addrV6(addr)
{}

Address::~Address() {}

std::string Address::ToString() const {
    return type_ == addrType::ipv4 ? 
        addrV4.toString() : addrV6.toString();
}

int Address::GetProtocol() const {
    return type_ == addrType::ipv4 ? 
        AF_INET : AF_INET6;
}

} // namespace net::ip