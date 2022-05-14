#include "crypto/math/big_int.hpp"
#include <algorithm>
#include <cstdint>
#include <vector>

namespace crypto {
namespace math {

BigInt::BigInt() {}

BigInt::BigInt(const std::string &num, byteOrder o) :
    bOrder_(o)
{
    sign_ = (num[0] == '-') ? 
        numberSign::kNegative : numberSign::kPositive;

    int len = num.size();
    int c = (o == byteOrder::kBigEnding) ?
        len : 1;
        
    for(int i = 0; i < len; i++) {
        int x = abs(len - c - i);
        literal_.emplace_back(num[x] - BI_ASCI_NUM_START);
    }
}

BigInt::BigInt(const std::int64_t num, byteOrder o) :
    bOrder_(o)
{    
    std::int64_t copy = (num < 0) ? -1 * num : num;
    sign_ = (num < 0) ? 
        numberSign::kNegative : numberSign::kPositive;

    if(o == byteOrder::kLittleEnding) {
        for(; copy > 0; copy /= 10)
            literal_.emplace_back(copy % 10);
    }
    else if(o == byteOrder::kBigEnding) {
        int len = 0;
        for(int i = copy; i > 0; i /= 10)
            len++;
        
        for(int i = len; i > 0; i--) {
            int nc = copy;
            int m = static_cast<int>(pow(10, i - 1));

            literal_.emplace_back((nc / m) % 10);
        }
    }
}

BigInt::~BigInt() {}

void BigInt::SwapSign() {
    sign_ = (sign_ == numberSign::kNegative) ?
        numberSign::kPositive : numberSign::kNegative;
}

BigIntLiteral BigInt::SwapLiteral(const BigIntLiteral &l) const {
    BigIntLiteral n;
    int size = l.size();

    for(int i = 0; i < size; i++)
        n.emplace_back(l[size - i - 1]);

    return n;
}

BigInt::MaxLiteral BigInt::GetMax(const BigInt &other) const {
    BigIntLiteral o = other.GetLiteral();
    if(other.GetOrder() != bOrder_)
        o = SwapLiteral(o);

    MaxLiteral m;
    if(literal_.size() >= other.GetSize()) {
        m.big_ = literal_;
        m.small_ = other.GetLiteral();
    }
    else {
        m.big_ = other.GetLiteral();
        m.small_ = literal_;
    }

    return m;
}

BigInt BigInt::operator+(const BigInt &other) {
    //?
    BigIntLiteral big = GetMax(other).big_;
    BigIntLiteral small = GetMax(other).small_;

    for(int i = 0; i < small.size(); i++) {
        int x = big[i] + small[i];

        if(x >= 10) {
            x = x - 10;
            if(i + 1 >= big.size())
                big.emplace_back(1);
            else
                big[i + 1]++;
        }
        big[i] = x;
    }

    literal_ = big;
    return *this;
}

BigInt BigInt::operator-(const BigInt &other) {
    return *this;
}

BigInt BigInt::operator*(const BigInt &other) {
    if(other.GetSign() == numberSign::kNegative)
        SwapSign();

    BigIntLiteral big = GetMax(other).big_;
    BigIntLiteral small = GetMax(other).small_;
    
    std::vector<BigIntLiteral> addVec;

    for(int i = 0; i < small.size(); i++) {
        BigIntLiteral loc;

        int r = 0;
        for(int j = 0; j < big.size(); j++) {
            int x = small[i] * big[j] + r;

            if(x >= 10) {
                loc.emplace_back(x % 10);
                r = x / 10;
                if(j + 1 >= big.size())
                    loc.emplace_back(r);
            }
            else {
                loc.emplace_back(x);
                r = 0;
            }
        }
        addVec.push_back(loc);
    }

    for(int i = 0; i < addVec.size(); i++) {
        for(int j = 0; j < i; j++)
            std::cout << " ";
        PrintLiteral(addVec[i]);
    }

    int len = addVec.size() + addVec[addVec.size() - 1].size() - 1;
    BigIntLiteral lat(len);
    for(auto &i : lat)
        i = 0;
    std::cout << "\n";
    for(int i = 0; i < len; i++) {
        int sum = 0;
        std::cout << " i: " << i << "\n"; 
        for(int j = 0; j < addVec.size(); j++) {
            int ind = i - j;
            //std::cout << "j: " << j << "\n";
            std::cout << "j: " << j << " ind: " << ind << "\n";
            if(ind < 0 || ind >= addVec[j].size()) {
                //std::cout << "ind < 0\n";
                continue;
            }
            int added = addVec[j][ind];
            sum += added;
            //std::cout << "add: " << sum << "\n";
        }
        sum += lat[i];

        if(sum >= 10) {
            //std::cout << "greater then 10!!!\n";
            lat[i] = sum - 10;
            lat[i + 1]++;
        }
        else {
            lat[i] = sum;
        }
    }
    PrintLiteral(lat);
    return *this;
}

BigInt BigInt::operator/(const BigInt &other) {
    return *this;
}

BigInt BigInt::operator%(const BigInt &other) {
    return *this;
}

bool BigInt::operator==(const BigInt &other) const {
    return true;
}

bool BigInt::operator!=(const BigInt &other) const {
    return true;
}

bool BigInt::operator<(const BigInt &other) const {
    return true;
}

bool BigInt::operator<=(const BigInt &other) const {
    return true;
}

bool BigInt::operator>(const BigInt &other) const {
    return true;
}

bool BigInt::operator>=(const BigInt &other) const {
    return true;
}

std::string BigInt::ToString() const {
    std::string ret = "";

    if(sign_ == numberSign::kNegative)
        ret += '-';

    for(const auto &i: literal_)
        ret += i + BI_ASCI_NUM_START;

    return ret;
}

std::size_t BigInt::GetSize() const {
    return literal_.size();
}

byteOrder BigInt::GetOrder() const {
    return bOrder_;
}

numberSign BigInt::GetSign() const {
    return sign_;
}

BigIntLiteral BigInt::GetLiteral() const {
    return literal_;
}

void BigInt::SwapEnding() {
    bOrder_ = (bOrder_ == byteOrder::kLittleEnding) ?
        byteOrder::kBigEnding : byteOrder::kLittleEnding;
    literal_ = SwapLiteral(literal_);
}

std::ostream& operator<<(std::ostream& os, const BigInt& num) {
    if(num.sign_ == numberSign::kNegative)
        os << '-';

    for(const auto &i: num.literal_) {
        char n = i + BI_ASCI_NUM_START;
        os << n;
    }

    return os;
}

void PrintLiteral(const BigIntLiteral &lit) {
    for(const auto &i : lit)
        std::cout << static_cast<int>(i);
    std::cout << "\n";
}

} // namespace math
} // namespace crypto

