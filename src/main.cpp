#include <iostream>
#include "net/base/resolver.hpp"

int main () {
    std::cout << "Address for www.google.com\n";
    net::ip::Resolver res;
    for(const auto &i: res.Resolve("www.google.com"))
        std::cout << i.ToString() << "\n";
}