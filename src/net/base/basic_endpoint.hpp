#ifndef NET_BASE_BASIC_ENDPOINT_HPP_
#define NET_BASE_BASIC_ENDPOINT_HPP_

#include <netinet/in.h>

#include "net/base/net_types.hpp"
#include "net/ip/address.hpp"

namespace net {

// Forward declaration
template<typename Proto>
class BasicEndpoint;

// Freind functions definitions
template<typename Proto>
bool operator==(const BasicEndpoint<Proto> &a, const BasicEndpoint<Proto> &b);
template<typename Proto>
bool operator!=(const BasicEndpoint<Proto> &a, const BasicEndpoint<Proto> &b);

// This class represent one endpoint in internet.
// It collect low level linux socket structs, which 
// you can use for connection.
template<typename Proto>
class BasicEndpoint {
    public:
        typedef Proto protoType;

        BasicEndpoint();
        BasicEndpoint(const ip::Address &addr, const portType port);
        
        ~BasicEndpoint();

        ip::Address getAddress() const;
        portType getPort() const;
        sockaddr_type* getData();
        int getAddressFamily() const;
        const sockaddr_type* getData() const;
        protoType getProtocol() const;

        bool isV4() const;
        bool isV6() const;

        bool isEmpty() const;

        friend bool operator==<>
            (const BasicEndpoint &a, const BasicEndpoint &b);
        friend bool operator!=<>
            (const BasicEndpoint &a, const BasicEndpoint &b);

    private:
        union sockTypeData{
            sockaddr_type base;
            sockaddr_v4_type v4;
            sockaddr_v6_type v6;
        } data_;
};

} // namespace net

#endif