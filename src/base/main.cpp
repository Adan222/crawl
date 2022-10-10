#include <cstddef>
#include <exception>
#include <iostream>
#include <memory>
#include <string>
#include <system_error>

#include "utils/buffer/mutable_buffer.hpp"
#include "net/base/connection.hpp"
#include "net/base/connect.hpp"
#include "net/base/tcp.hpp"
#include "utils/buffer/const_buffer.hpp"

int main () {
    std::string host = "www.google.com";
    net::tcp::resolver res;
    net::tcp::resolver::query q(host, "http");

    std::unique_ptr<net::Connection> conn;
    std::cout << "Connecting to: " << host << "\n";
    try{
        conn = net::connect(res.resolve(q));

        std::string http = "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n";
        size_t sendLen = conn->send(http);

        utils::MutableBuffer buff = std::string("");
        while (conn->recv(buff))
            std::cout << std::string(buff) << "\n";    
        
    } catch(const std::exception &e) {
        std::cerr << e.what() << "\n";
    }
} 
