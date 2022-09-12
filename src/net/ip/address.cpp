#include "net/ip/address.hpp"

namespace net::ip {

Address::Address() :
    type_(),
    v4(),
    v6()
{}

Address::Address(const AddressV4 &addr) : 
    type_(addrType::ipv4),
    v4(addr),
    v6()
{}

Address::Address(const AddressV6 &addr): 
    type_(addrType::ipv6),
    v4(),
    v6(addr)
{}

Address::~Address() {}

bool Address::isV4() const {
    return type_ == addrType::ipv4;
}

bool Address::isV6() const {
    return type_ == addrType::ipv6;
}

std::string Address::toString() const {
    return (type_ == addrType::ipv4) ? 
        v4.toString() : v6.toString();
}


} // namespace net::ip