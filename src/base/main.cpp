#include <iostream>

#include "net/dns/resolver.hpp"

int main () {
    net::ip::Resolver res;

    for(const auto &i : res.resolve("www.google.com"))
        std::cout << i.toString() << "\n";
}