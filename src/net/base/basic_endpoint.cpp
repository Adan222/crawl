#include "net/base/basic_endpoint.hpp"
#include "net/ip/address_v4.hpp"
#include "net/ip/address_v6.hpp"
#include <netinet/in.h>
#include <sys/socket.h>

namespace net {

template<typename Proto>
BasicEndpoint<Proto>::BasicEndpoint() {}

template<typename Proto>
BasicEndpoint<Proto>::BasicEndpoint(
        const ip::Address &addr, const portType port)
{
    if(addr.isV6()) {
        data_.v4.sin_family = AF_INET;
        data_.v4.sin_port = htons(port);
        data_.v4.sin_addr = htonl(addr.toV4().toInt());
    }
    else {
        ip::AddressV6::v6ByteType bytes =
            addr.toV6().toBytes();

        data_.v6.sin6_family = AF_INET6;
        data_.v6.sin6_port = htons(port);
        data_.v6.sin6_flowinfo = 0;
        ::memcpy(bytes.data(), data_.v6.sin6_addr, 16);

        // WARNING: If somethink`s wont work check ipv6 scoek_id
        data_.v6.sin6_scope_id = 0;
    }
}

template<typename Proto>
BasicEndpoint<Proto>::~BasicEndpoint<Proto>() {}

template<typename Proto>
void BasicEndpoint<Proto>::setAddress(const ip::Address &addr) {
    // that`s cleaver
    BasicEndpoint tmp(addr, getPort());
    data_ = tmp.data_;
}

template<typename Proto>
void BasicEndpoint<Proto>::setPort(const portType port) {
    if(isV4())
        data_.v4.sin_port = htons(port);
    else
        data_.v6.sin6_port = htons(port);
}

template<typename Proto>
ip::Address BasicEndpoint<Proto>::getAddress() const {
    if(isV4())
        return ip::AddressV4(data_.v4.sin_addr);
    else
        return ip::AddressV6(data_.v6.sin6_addr);
}

template<typename Proto>
portType BasicEndpoint<Proto>::getPort() const {
    if(isV4())
        return ntohs(data_.v4.sin_port);
    else
        return ntohs(data_.v6.sin6_port);
}

template<typename Proto>
sockaddr_type* BasicEndpoint<Proto>::getData() const {
    return &data_.base;
}

template<typename Proto>
// TODO: Return type should be protoType
Proto BasicEndpoint<Proto>::getProtocol() const {
    if(isV4())
        return Proto::v4();
    else
        return Proto::v6();
}

template<typename Proto>
bool BasicEndpoint<Proto>::isV4() const {
    return data_.base.sa_family == AF_INET;
}

template<typename Proto>
bool BasicEndpoint<Proto>::isV6() const {
    return data_.base.sa_family == AF_INET6;
}

} // namespace net