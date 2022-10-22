#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <string>

#include <catch2/catch_test_macros.hpp>

namespace test {

void hexDump(void *data, std::size_t size);
std::string hexDumpStr(void *data, std::size_t size);

void decDump(void *data, std::size_t size);
std::string decDumpStr(void *data, std::size_t size);


} // namespace test`