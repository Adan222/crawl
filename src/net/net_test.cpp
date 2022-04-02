#include <iostream>

#include "net/ip/address_v4.hpp"
#include "net/ip/resolver.hpp"

int main() {
    std::cout << "Netlib test!!!\n";
    net::ip::Resolver res;
    auto resoult = res.Resolve("www.google.com");

    for(const auto &i : resoult)
        std::cout << i.ToString() << "\n";
}