#ifndef CRYPTO_MATH_BIG_INT_HPP_
#define CRYPTO_MATH_BIG_INT_HPP_

#include <iostream>
#include <ostream>
#include <vector>
#include <string>

#include <cstddef>
#include <cstdint>
#include <cmath>

namespace crypto {
namespace math {

constexpr static char BI_ASCI_NUM_START = 48;

enum byteOrder {
    kLittleEnding,
    kBigEnding
};

enum numberSign {
    kPositive,
    kNegative
};

typedef std::vector<std::uint8_t> BigIntLiteral;

void PrintLiteral(const BigIntLiteral &lit);

class BigInt {
    private:
        BigIntLiteral literal_;

        numberSign sign_;
        byteOrder bOrder_;

        void SwapSign();
        BigIntLiteral SwapLiteral(const BigIntLiteral &l) const;

        /*
         * Struct conatin the bigest and smallest 
         * literal. GetMax() compare literal of given
         * object with literaal of local object and return
         * this struct. It also convert "other" litaral if 
         * it`s different then our.
         */
        struct MaxLiteral {
            BigIntLiteral big_;
            BigIntLiteral small_;
        };
        MaxLiteral GetMax(const BigInt &other) const;

    public:
        BigInt();
        BigInt(const std::string &num, byteOrder o = kLittleEnding);
        BigInt(const std::int64_t num, byteOrder o = kLittleEnding);
        ~BigInt();

        // Arithmetic operators
        BigInt operator+(const BigInt &other);
        BigInt operator-(const BigInt &other);
        BigInt operator*(const BigInt &other);
        BigInt operator/(const BigInt &other);
        BigInt operator%(const BigInt &other);

        // Comparison operators
        bool operator==(const BigInt &other) const;
        bool operator!=(const BigInt &other) const;
        bool operator<(const BigInt &other) const;
        bool operator<=(const BigInt &other) const;
        bool operator>(const BigInt &other) const;
        bool operator>=(const BigInt &other) const;

        std::string ToString() const;

        std::size_t GetSize() const;
        byteOrder GetOrder() const;
        numberSign GetSign() const;
        BigIntLiteral GetLiteral() const;

        void SwapEnding();

        friend std::ostream& operator<<(std::ostream &os, const BigInt &num);
};

std::ostream& operator<<(std::ostream& os, const BigInt& num);
} // namespace math
} // namespace crypto

#endif