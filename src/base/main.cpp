#include <chrono>
#include <exception>
#include <iostream>
#include <string>
#include <system_error>
#include <thread>

#include "base/buffer/mutable_buffer.hpp"
#include "net/base/connection.hpp"
#include "net/base/tcp.hpp"
#include "base/buffer/concept.hpp"
#include "buffer/const_buffer.hpp"

int main () try {
    net::tcp::resolver res;
    net::tcp::resolver::query q("www.google.com", "http");

    net::Connection conn;
    conn.connect(res.resolve(q));

    std::string http = "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n";

    size_t send_len = conn.send(http);
    std::cout << send_len << "\n";

    utils::MutableBuffer buff = std::string("");

    while(conn.recv(buff))
        std::cout << std::string(buff) << "\n";
} 
catch(const std::exception &e) {
    std::cout << "error: " << e.what() << "\n";
}