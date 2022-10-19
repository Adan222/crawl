#pragma once

#include <iostream>

#include "catch2/catch_test_macros.hpp"

#include "net/base/net_types.hpp"
#include "net/base/tcp.hpp"

namespace test {
    bool isValidFamily(const int af);
    void dumpEndpoint(const net::tcp::endpoint &end);
}