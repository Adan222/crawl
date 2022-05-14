#include <iostream>
#include "crypto/math/big_int.hpp"

int main() {
    std::cout << "CryptoLib test!!!\n";

    crypto::math::BigInt one("690213");
    crypto::math::BigInt two("124122");

    one * two;
}