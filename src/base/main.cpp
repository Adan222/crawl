#include <chrono>
#include <exception>
#include <iostream>
#include <string>
#include <system_error>
#include <thread>

#include "utils/buffer/mutable_buffer.hpp"
#include "net/base/connection.hpp"
#include "net/base/tcp.hpp"
#include "utils/buffer/const_buffer.hpp"

int main () try {
    
} 
catch(const std::exception &e) {
    std::cout << "error: " << e.what() << "\n";
}