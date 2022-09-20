#include "net/ip/address.hpp"
#include "net/ip/address_v4.hpp"
#include "net/ip/address_v6.hpp"

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

Address Address::operator=(const AddressV4 &addr) {
    v4 = addr;
    v6 = AddressV6();

    type_ = addrType::ipv4;
    return *this;
}

Address Address::operator=(const AddressV6 &addr) {
    v4 = AddressV4();
    v6 = addr;

    type_ = addrType::ipv6;
    return *this;
}

Address Address::operator=(const Address &other) {
    if(other.type_ == addrType::ipv4)
        *this = other.toV4();
    else
        *this = other.toV6();
    
    return *this;
}

Address::~Address() {}

AddressV4 Address::toV4() const {
    return v4;
}

AddressV6 Address::toV6() const {
    return v6;
}

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

bool operator==(const Address &a, const Address &b) {
    if(a.type_ != b.type_)
        return false;
    if(a.type_ == Address::addrType::ipv4)
        return a.v4 == b.v4;
    else
        return a.v6 == b.v6;
}

bool operator!=(const Address &a, const Address &b) {
    return !(a == b);
}


} // namespace net::ip