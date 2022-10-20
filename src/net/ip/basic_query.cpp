#include "net/ip/basic_query.hpp"
#include "net/base/tcp.hpp"
#include <string>

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
BasicQuery<Proto>::BasicQuery(const std::string &host) :
    hint_(),
    hostName_(host),
    serviceName_()
{
    createEmptyHint();
}

template<typename Proto>
BasicQuery<Proto>::BasicQuery(const std::string &host,
            const std::string &service) :
    hint_(),
    hostName_(host),
    serviceName_(service)
{
    createEmptyHint();
}

template<typename Proto>
BasicQuery<Proto>::BasicQuery(const std::string &host, portType port) :
    BasicQuery(host, std::to_string(port))
{}

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
const char* BasicQuery<Proto>::getServiceName() const {
    return serviceName_.empty() || serviceName_ == "" ? 
        nullptr : serviceName_.c_str();
}

template<typename Proto>
void BasicQuery<Proto>::createEmptyHint() {
    typename Proto::endpoint endpoint;

    ::memset(&hint_, 0, sizeof(addrinfo_type));
    hint_.ai_family = AF_UNSPEC;
    hint_.ai_socktype = endpoint.getProtocol().sockType();
    hint_.ai_protocol = endpoint.getProtocol().proto();
    hint_.ai_flags = AI_PASSIVE;
}

template class BasicQuery<tcp>;

} // namespace net::ip