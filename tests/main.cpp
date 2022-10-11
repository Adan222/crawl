#include <catch2/catch_session.hpp>

#include <cstring>

#include "mem_dump.hpp"

int main(int argc, char **argv) {
    constexpr int x = 52;
    char arr[x];
    memset(arr, (int)'a', x);

    test::hexDump(arr, x);
}