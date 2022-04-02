#include "crypto/math/big_int.hpp"
#include <string>

namespace crypto {
namespace math {

BigInt::BigInt() {}

BigInt::BigInt(const std::string &number) :
    literal_(number.size())
{
    FromString(number);
}

BigInt::~BigInt() {}

void BigInt::FromString(const std::string &number) {
    for(const auto &i : number)
        literal_.emplace_back(i);
}

BigInt BigInt::operator+(const BigInt &other) const {
    
}

BigInt BigInt::operator-(const BigInt &other) const {

}

BigInt BigInt::operator*(const BigInt &other) const {

}

BigInt BigInt::operator/(const BigInt &other) const {

}

BigInt BigInt::operator^(const int number) const {

}

bool BigInt::operator==(const BigInt &other) const {

}

bool BigInt::operator!=(const BigInt &other) const {

}

bool BigInt::operator<(const BigInt &other) const {

}

bool BigInt::operator<=(const BigInt &other) const {

}

bool BigInt::operator>(const BigInt &other) const {

}

bool BigInt::operator>=(const BigInt &other) const {

}

} // namespace math
} // namespace crypto

