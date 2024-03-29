#include "net/ip/basic_resoults.hpp"
#include "net/base/tcp.hpp"

namespace net::ip {

template<typename Proto>
BasicResoults<Proto>::BasicResoults() :
    BasicResoultsIterator<Proto>()
{}

template<typename Proto>
BasicResoults<Proto>::~BasicResoults() {}

template<typename Proto>
BasicResoults<Proto>::BasicResoults(const BasicResoults &other) :
    BasicResoultsIterator<Proto>(other)
{}

template<typename Proto>
bool operator==(const BasicResoults<Proto> &a,
    const BasicResoults<Proto> &b)
{
    return a.equal(b);
}

template<typename Proto>
bool operator!=(const BasicResoults<Proto> &a,
    const BasicResoults<Proto> &b)
{
    return !a.equal(b);
}

template<typename Proto>
BasicResoults<Proto> BasicResoults<Proto>::create(addrinfo_type *addr)
{
    BasicResoults<Proto> end;
    while (addr) {
        const int af = addr->ai_family;
        if(af == AF_INET || af == AF_INET6) {
            endpoint point;
            ::memcpy(point.getData(), addr->ai_addr, addr->ai_addrlen);

            end.data_.push_back(point);
        }
        addr = addr->ai_next;
    }

    freeaddrinfo(addr);
    return end;
}

template class BasicResoults<tcp>;

bool operator==(const BasicResoults<tcp> &a,
    const BasicResoults<tcp> &b);
bool operator!=(const BasicResoults<tcp> &a,
    const BasicResoults<tcp> &b);

} // namespace net::ip