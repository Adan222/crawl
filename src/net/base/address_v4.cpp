#include "net/base/address_v4.hpp"

namespace net::ip {

AddressV4::AddressV4() :
    BasicAddress(),
    addr_(0)
{}

AddressV4::AddressV4(const AddrLiteral addr) : 
    BasicAddress(),
    addr_(addr)
{}

AddressV4::~AddressV4() {}

std::string AddressV4::toString() const {
    std::uint8_t bytes[4];
    std::memcpy(bytes, &addr_, 4);

    std::string ip = "";
    for(int i = 0; i < 4; i++) {
        ip += std::to_string(bytes[i]);
        if(i < 3)
            ip += ".";
    }
    return ip;

}

} // namespace net::ip