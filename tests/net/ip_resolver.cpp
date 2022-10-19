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

TEST_CASE("TCP resolver test", "[resolver]") {
    net::tcp::resolver res;
    net::tcp::resolver::query q("www.google.com", "http");

    for(const auto &i : res.resolve(q)) {
        dumpEndpoint(i);
        REQUIRE(isValidFamily(i.getAddressFamily()));
    }
}

} // namespace test