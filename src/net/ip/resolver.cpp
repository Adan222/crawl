#include "net/ip/resolver.hpp"
#include "net/base/tcp.hpp"

namespace net::ip {

template<typename Proto>
BasicResolver<Proto>::BasicResolver() {}

template<typename Proto>
BasicResolver<Proto>::~BasicResolver() {}

template<typename Proto>
BasicResoults<Proto> BasicResolver<Proto>::resolve(const query &q)  {
    addrinfo_type *res;

    // TODO: Error handling for getaddrinfo
    if (::getaddrinfo(q.getHostName().c_str(),
                      q.getServiceName().c_str(),
                      &q.getHint(), 
                      &res) != 0)
        std::cerr << "resolve error\n";
    
    return BasicResoults<Proto>::create(res);
}

template class BasicResolver<tcp>;

} // namespace net:ip