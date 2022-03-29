#include "net/ip/address.hpp"
#include <sys/socket.h>

namespace net {
namespace ip {

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
    if(type_ == addrType::ipv4)
        return addrV4.toString();
    else
        return addrV6.toString();        
}

int Address::GetProtocol() const {
    if(type_ == addrType::ipv4)
        return AF_INET;
    else
        return AF_INET6;
}

} // namespace ip
} // namespace net