#include "mem_dump.hpp"
#include <sstream>

namespace test {

using ios_base_func = std::ios_base &(std::ios_base&);

inline static void printOffset(std::stringstream &s, int i) {
    s << std::setw(4) << std::setfill('0') << std::hex << i << " ";
}

inline static void printByte(std::stringstream &s, unsigned char i, ios_base_func base) {
    s << std::setw(2) << base << static_cast<int>(i) << " ";
}

inline static void printdata(std::stringstream &s, char data[]) {
    s << "|" << data << "|\n";
}

inline static unsigned char toChar(unsigned char c) {
    if(c > 126 || c < 32)
        return '.';
    else
        return c;
}

inline static void printGap(std::stringstream &s, int x) {
    for(int i = 0; i < x; i++)
        s << "   ";
}

inline static std::string 
    dump(void *data, std::size_t size, ios_base_func base) 
{
    constexpr int kChunkSize = 16;

    using byteType = char;
    const byteType *byte = static_cast<const byteType*>(data);

    byteType chunk[kChunkSize + 1];

    std::stringstream ss;

    ss << "Data size: " << size << "\n";
    for(int i = 0; i < size; i++) {
        if((i % 16) == 0) {
            if(i != 0)
                printdata(ss, chunk);
            printOffset(ss, i);
        }
        printByte(ss, byte[i], base);

        chunk[i % kChunkSize] = toChar(byte[i]);
        chunk[(i % kChunkSize) + 1] = '\0';

        if((i + 1) == size) {
            const int ro = std::ceil(static_cast<float>(size) / kChunkSize);
            const int x = (ro * kChunkSize) - size;

            printGap(ss, x);
            printdata(ss, chunk);
        }
    }
    ss << "\n";
    return ss.str();
}

void hexDump(void *data, std::size_t size) {
    UNSCOPED_INFO("=====\n");
    UNSCOPED_INFO(dump(data, size, std::hex));
}

std::string hexDumpStr(void *data, std::size_t size) {
    return dump(data, size, std::hex);
}

void decDump(void *data, std::size_t size) {
    UNSCOPED_INFO("=====\n");
    UNSCOPED_INFO(dump(data, size, std::dec));
}

std::string decDumpStr(void *data, std::size_t size) {
    return dump(data, size, std::dec);
}


} // namespace test