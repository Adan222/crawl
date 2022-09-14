#include "net/base/tcp.hpp"

namespace net {

tcp::tcp(int af) :
    af_(af)
{}

tcp tcp::v4() noexcept {
    return tcp(AF_INET);
}

tcp tcp::v6() noexcept {
    return tcp(AF_INET);
}

constexpr int tcp::type() const {
    return SOCK_STREAM;
}

constexpr int tcp::proto() const {
    return IPPROTO_TCP;
}

constexpr int tcp::family() const {
    return af_;
}



} // namespace net