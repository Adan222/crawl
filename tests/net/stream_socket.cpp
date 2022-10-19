#include <catch2/catch_test_macros.hpp>

#include "net/base/stream_socket.hpp"

namespace test {

TEST_CASE("Stream socket", "[socket]") {
    net::tcp::resolver res;
    net::tcp::resolver::query q("www.google.com", "http");

    for(const auto &i : res.resolve(q)) {
        REQUIRE_NOTHROW(net::StreamSocket(i));
    }
}

} // namespace test