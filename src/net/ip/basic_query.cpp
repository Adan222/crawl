#include "net/ip/basic_query.hpp"
#include "net/base/tcp.hpp"

namespace net::ip {

template<typename Proto>
BasicQuery<Proto>::BasicQuery() : 
    hint_(),
    hostName_(),
    serviceName_()
{
    ::memset(&hint_, 0, sizeof(addrinfo_type));
}

template<typename Proto>
BasicQuery<Proto>::BasicQuery(const std::string &host,
            const std::string &service) :
    hint_(),
    hostName_(host),
    serviceName_(service)
{
    typename Proto::endpoint endpoint;

    ::memset(&hint_, 0, sizeof(addrinfo_type));
    hint_.ai_family = AF_UNSPEC;
    hint_.ai_socktype = endpoint.getProtocol().sockType();
    hint_.ai_protocol = endpoint.getProtocol().proto();
    hint_.ai_flags = AI_PASSIVE;
}

template<typename Proto>
BasicQuery<Proto>::~BasicQuery() {}

template<typename Proto>
const addrinfo_type& BasicQuery<Proto>::getHint() const {
    return hint_;
}

template<typename Proto>
std::string BasicQuery<Proto>::getHostName() const {
    return hostName_;
}

template<typename Proto>
std::string BasicQuery<Proto>::getServiceName() const {
    return serviceName_;
}

template class BasicQuery<tcp>;

} // namespace net::ip