#include "ip_address.hpp"
#include "catch2/catch_message.hpp"

namespace test {

std::string dumpAddressV4str(const net::ip::AddressV4 &addr) {
    std::stringstream ss;

    ss << "Address: " << addr.toString() << "\n";

    auto v4 = addr.toInt();
    auto bytes = reinterpret_cast<const uint8_t*>(&v4);

    ss << "Each octet in hex:\n";
    for(int i = 0; i < 4; i++)
        ss << std::setw(2) << std::hex << bytes[i] << " ";

    return ss.str();
}

void dumpAddressV4(const net::ip::AddressV4 &addr) {
    UNSCOPED_INFO(dumpAddressV4str(addr));
}

std::string dumpAddressV6str(const net::ip::AddressV6 &addr) {
    std::stringstream ss;

    ss << "Address: " << addr.toString() << "\n";
    ss << "Scope: " << addr.getScope() << "\n";
    auto bytes = addr.toBytes();

    return ss.str();
}

void dumpAddressV6(const net::ip::AddressV6 &addr) {
    UNSCOPED_INFO(dumpAddressV6str(addr));
}

std::string dumpAddressStr(const net::ip::Address &addr) {
    if(addr.isV4())
        return dumpAddressV4str(addr.toV4());
    else
        return dumpAddressV6str(addr.toV6());
}

void dumpAddress(const net::ip::Address &addr) {
    UNSCOPED_INFO("=====\n");
    UNSCOPED_INFO(dumpAddressStr(addr));
}




} // namespace test