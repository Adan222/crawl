#include "net/ip/address_v4.hpp"
#include "net/base/net_types.hpp"
#include <cstdint>
#include <cstring>

namespace net::ip {

AddressV4::AddressV4(){
    addr_.s_addr = 0;
}

AddressV4::AddressV4(const v4Type addr) {
    addr_.s_addr = addr;
}

AddressV4::AddressV4(const v4ByteType &bytes) {
    ::memcpy(&addr_, bytes.data(), 4);
}

AddressV4::~AddressV4() {}

// Here we wrire our own conversion couse it`s
// easy, but shouldn`t we use inet_ntop? 
std::string AddressV4::toString() const {
    // Treat it like an array of octets 
    const uint8_t *b = reinterpret_cast<const uint8_t*>(&addr_);

    std::string ip = "";
    for(int i = 0; i < 4; i++) {
        ip += std::to_string(b[i]);
        if(i < 3)
            ip += ".";
    }
    return ip;
}

namespace V4 {

AddressV4 fromString(const std::string &str) {
    return fromString(str.c_str());
}

AddressV4 fromString(const char *str) {
    in4_addr_type addr;
    ::inet_pton(AF_INET, str, &addr);

    return AddressV4(addr.s_addr);
}

} // namespace V4

} // namespace net::ip