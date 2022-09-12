#include "net/dns/resolver.hpp"

namespace net::ip {

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

AddressList Resolver::resolve(const std::string &domain) {
    /*struct addrinfo *res;

    if(int status = getaddrinfo(domain.c_str(), "http", &hint_, &res))
        std::cerr << "Resolve error: " << gai_strerror(status) << "\n";

    AddressList list;
    for(struct addrinfo* i = res; i != nullptr; i = i->ai_next) {
        if(i->ai_family == AF_INET) {
            struct sockaddr_in *ip = (struct sockaddr_in *)i->ai_addr;
            list.push_back(AddressV4(ip->sin_addr.s_addr));   
        }
        else {
            struct sockaddr_in6 *ip = (struct sockaddr_in6 *)i->ai_addr;

            list.push_back(AddressV6(lit));   
        }
    }
    
    freeaddrinfo(res);
    return list; */
    return AddressList();
}



} // namespace net:ip