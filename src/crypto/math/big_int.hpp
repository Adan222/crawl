#ifndef CRYPTO_MATH_BIG_INT_HPP_
#define CRYPTO_MATH_BIG_INT_HPP_

#include <cstdint>
#include <vector>
#include <string>

namespace crypto {
namespace math {

class BigInt {
    private:
        std::vector<std::uint8_t> literal_;

        void FromString(const std::string &number);

    public:
        BigInt();
        BigInt(const std::string &number);
        ~BigInt();

        // Arithmetic operators
        BigInt operator+(const BigInt &other) const;
        BigInt operator-(const BigInt &other) const;
        BigInt operator*(const BigInt &other) const;
        BigInt operator/(const BigInt &other) const;
        BigInt operator^(const int number) const;

        // Comparison operators
        bool operator==(const BigInt &other) const;
        bool operator!=(const BigInt &other) const;
        bool operator<(const BigInt &other) const;
        bool operator<=(const BigInt &other) const;
        bool operator>(const BigInt &other) const;
        bool operator>=(const BigInt &other) const;
};

} // namespace math
} // namespace crypto

#endif