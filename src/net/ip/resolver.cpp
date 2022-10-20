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
    net::error_code ec;

    func::getaddrinfo(q.getHostName().c_str(), q.getServiceName(),
        &q.getHint(), 
        &res, 
        ec);
    
    if(ec)
        error::throwError(ec);
    
    return BasicResoults<Proto>::create(res);
}

template class BasicResolver<tcp>;

} // namespace net:ip