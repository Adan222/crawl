#include "net/ip/address.hpp"
#include <iostream>

int main () {
    std::cout << net::ip::V4::fromString("216.58.215.110").toString() << "\n";
}