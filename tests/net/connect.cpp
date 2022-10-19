#include "connect.hpp"
#include "tests/net/test.hpp"

namespace test {

TEST_CASE("TCP connect", "[connection]") {
    net::tcp::resolver res;
    net::tcp::resolver::query q(test::host, test::port);

    for(const auto &i : res.resolve(q)) {
        auto sock = net::StreamSocket(i);
        REQUIRE_NOTHROW(net::connSocket(sock, i));
    }
}

} // namespace test