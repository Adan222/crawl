#include <iostream>

#include "net/base/tcp.hpp"

int main () {
    net::tcp::resolver res;
    net::tcp::resolver::query q("www.google.com", "http");

    auto r = res.resolve(q);
    for(const auto &i : r)
        std::cout << i.getAddress().toString() << "\n";
}