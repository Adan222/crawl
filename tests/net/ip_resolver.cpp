#include "ip_resolver.hpp"

namespace test {

bool isValidFamily(const int af) {
    if(af == AF_INET || af == AF_INET6)
        return true;
    return false;
}

void dumpEndpoint(const net::tcp::endpoint &end) {
    auto protoStr = [](int p) -> std::string {
        if(p == AF_INET) 
            return "AF_INET";
        else if (p == AF_INET6)
            return "AF_INET6";
        else
            return "UNKNOWN";
    };
    std::cout << "=====\n";
    std::cout << "Endpoint with address: " << end.getAddress().toString() << "\n";
    std::cout << "On port: " << end.getPort() << "\n";
    std::cout << "is Empty: " << std::boolalpha << end.isEmpty() << "\n"; 
    const int af = end.getAddressFamily();
    std::cout << "Address family: " << protoStr(af) << "(" << af << ")\n\n"; 
}

TEST_CASE("TCP endpoint", "[endpoint]") {
    net::tcp::resolver res;
    net::tcp::resolver::query q(test::host, test::port);

    for(const auto &i : res.resolve(q)) {
        dumpEndpoint(i);
        REQUIRE(isValidFamily(i.getAddressFamily()));
    }
}

TEST_CASE("TCP resolver", "[resolver]") {
    net::tcp::resolver res;
    net::tcp::resolver::query q(test::host, test::port);

    REQUIRE_NOTHROW(res.resolve(q));
}

TEST_CASE("TCP resolver failure", "[resolver]") {
    net::tcp::resolver res;
    net::tcp::resolver::query q(badHost, test::port);

    REQUIRE_THROWS(res.resolve(q));
}

} // namespace test