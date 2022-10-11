#include "mem_dump.hpp"
#include <cmath>
#include <iomanip>

namespace test {

inline static void printOffset(int i) {
    std::cout << std::setw(4) << std::setfill('0') << std::hex << i << " ";
}

inline static void printHex(unsigned char i) {
    std::cout << std::setw(2) << std::hex << static_cast<int>(i) << " ";
}

inline static void printdata(char data[]) {
    std::cout << "|" << data << "|\n";
}

inline static unsigned char toChar(unsigned char c) {
    if(c > 126 || c < 32)
        return '.';
    else
        return c;
}

inline static void printGap(int x) {
    for(int i = 0; i < x; i++)
        std::cout << "   ";
}

void hexDump(void *data, std::size_t size) {
    constexpr int kChunkSize = 16;

    using byteType = char;
    const byteType *byte = static_cast<const byteType*>(data);

    byteType chunk[kChunkSize + 1];
    for(int i = 0; i < size; i++) {
        if((i % 16) == 0) {
            if(i != 0)
                printdata(chunk);
            printOffset(i);
        }
        printHex(byte[i]);

        chunk[i % kChunkSize] = toChar(byte[i]);
        chunk[(i % kChunkSize) + 1] = '\0';

        if((i + 1) == size) {
            const int ro = std::ceil(static_cast<float>(size) / kChunkSize);
            const int x = (ro * kChunkSize) - size;

            printGap(x);
            printdata(chunk);
        }
    }
}

} // namespace test