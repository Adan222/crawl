#include "net/base/basic_endpoint.hpp"
#include "net/base/tcp.hpp"
#include "net/ip/address_v6.hpp"
#include <cstring>

namespace net {

template<typename Proto>
BasicEndpoint<Proto>::BasicEndpoint() {
    memset(&data_, 0, sizeof(sockTypeData));
}

template<typename Proto>
BasicEndpoint<Proto>::BasicEndpoint(
        const ip::Address &addr, const portType port)
{
    if(addr.isV4()) {
        data_.v4.sin_family = AF_INET;
        data_.v4.sin_port = htons(port);
        data_.v4.sin_addr.s_addr = htonl(addr.toV4().toInt());
    }
    else {
        ip::AddressV6::v6ByteArray bytes =
            addr.toV6().toBytes();

        data_.v6.sin6_family = AF_INET6;
        data_.v6.sin6_port = htons(port);
        data_.v6.sin6_flowinfo = 0;
        ::memcpy(bytes.data(), &data_.v6.sin6_addr, 16);

        // WARNING: If somethink`s wont work check ipv6 scoek_id
        data_.v6.sin6_scope_id = 0;
    }
}

template<typename Proto>
BasicEndpoint<Proto>::~BasicEndpoint() {}

template<typename Proto>
ip::Address BasicEndpoint<Proto>::getAddress() const {
    if(isV4())
        return ip::AddressV4(data_.v4.sin_addr.s_addr);
    else {
        ip::AddressV6::v6ByteArray byte;
        ::memcpy(byte.data(), data_.v6.sin6_addr.s6_addr, 16);
        auto scope = data_.v6.sin6_scope_id;

        return ip::AddressV6(byte, scope);
    }
}

template<typename Proto>
portType BasicEndpoint<Proto>::getPort() const {
    if(isV4())
        return ntohs(data_.v4.sin_port);
    else
        return ntohs(data_.v6.sin6_port);
}

template<typename Proto>
sockaddr_type* BasicEndpoint<Proto>::getData() {
    return &data_.base;
}

template<typename Proto>
const sockaddr_type* BasicEndpoint<Proto>::getData() const {
    return &data_.base;
}

template<typename Proto>
int BasicEndpoint<Proto>::getAddressFamily() const {
    return data_.base.sa_family;
}

template<typename Proto>
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

template<typename Proto>
bool BasicEndpoint<Proto>::isEmpty() const {
    // idk it`s right way to check it
    return data_.base.sa_family == 0;
}

template<typename Proto>
bool operator==(const BasicEndpoint<Proto> &a, const BasicEndpoint<Proto> &b)
{
    return a.getAddress() == b.getAddress();
}

template<typename Proto>
bool operator!=(const BasicEndpoint<Proto> &a, const BasicEndpoint<Proto> &b)
{
    return !(a == b);
}

template class BasicEndpoint<tcp>;
template bool operator==(const BasicEndpoint<tcp> &a, const BasicEndpoint<tcp> &b);
template bool operator!=(const BasicEndpoint<tcp> &a, const BasicEndpoint<tcp> &b);

} // namespace net