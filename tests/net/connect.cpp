#include "connect.hpp"
#include "tests/net/ip_address.hpp"

namespace test {

static void dumpEndpointMemory(const net::tcp::endpoint &end) {
    net::socklen_type len = end.isV4() ? 
        sizeof(net::sockaddr_v4_type) : sizeof(net::sockaddr_v6_type);

    auto data = const_cast<net::sockaddr_type*>(end.getData());
    hexDump(data, len);
}

TEST_CASE("TCP connect", "[connection]") {
    net::tcp::resolver res;
    net::tcp::resolver::query q(test::host, test::port);

    for(const auto &i : res.resolve(q)) {
        auto sock = net::StreamSocket(i);
        dumpEndpoint(i);
        dumpEndpointMemory(i);
        dumpAddress(i.getAddress());

        /**
         * connection may throw:
         *      Address family not supported by protocol
         *
         * error when ipv6 isn`t supported by platform.
         * So we have to make separate tests for each 
         * internet protocol.
         * TODO: Make test for each internet protocol
         */
        //CHECK_NOTHROW(net::connSocket(sock, i));
    }
}

} // namespace test