#include "net/ip/resolver.hpp"

namespace net {
namespace ip {

Resolver::Resolver() {
    CreateHint();
}

Resolver::~Resolver() {}

void Resolver::CreateHint() {
    memset(&hint_, 0, sizeof(hint_));
    hint_.ai_family = AF_UNSPEC;
    hint_.ai_socktype = SOCK_STREAM;
    hint_.ai_flags = AI_PASSIVE;
}

AddressList Resolver::Resolve(const std::string &domain) {
    struct addrinfo *res;

    if(int status = getaddrinfo(domain.c_str(), "http", &hint_, &res))
        std::cout << "Resolve error: " << gai_strerror(status) << "\n";

    AddressList list;
    for(struct addrinfo* i = res; i != nullptr; i = i->ai_next) {
        if(i->ai_family == AF_INET) {
            struct sockaddr_in *ip = (struct sockaddr_in *)i->ai_addr;
            list.push_back(AddressV4(ip->sin_addr.s_addr));   
        }
        else {
            struct sockaddr_in6 *ip = (struct sockaddr_in6 *)i->ai_addr;
            list.push_back(AddressV6(ip->sin6_addr.s6_addr));   
        }
    }
    
    freeaddrinfo(res);
    return list;
}



} // namespace ip
} // namespace net