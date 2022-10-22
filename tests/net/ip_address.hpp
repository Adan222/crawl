#pragma once

#include <string>
#include <sstream>
#include <iomanip>

#include <catch2/catch_test_macros.hpp>

#include "net/ip/address.hpp"
#include "net/ip/address_v4.hpp"
#include "net/ip/address_v6.hpp"

namespace test {

std::string dumpAddressV4str(const net::ip::AddressV4 &addr);
void dumpAddressV4(const net::ip::AddressV4 &addr);

std::string dumpAddressV6str(const net::ip::AddressV6 &addr);
void dumpAddressV6(const net::ip::AddressV6 &addr);

std::string dumpAddresSstr(const net::ip::Address &addr);
void dumpAddress(const net::ip::Address &addr);


} // namespace test
