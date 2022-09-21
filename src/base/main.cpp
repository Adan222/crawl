#include <iostream>

#include "net/base/connection.hpp"
#include "net/base/tcp.hpp"

int main () {
    net::tcp::resolver res;
    net::tcp::resolver::query q("www.google.com", "http");

    net::Connection conn;
    conn.connect(res.resolve(q));
}