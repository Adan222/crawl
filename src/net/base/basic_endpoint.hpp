#ifndef NET_BASE_BASIC_ENDPOINT_HPP_
#define NET_BASE_BASIC_ENDPOINT_HPP_

#include <netinet/in.h>

#include "net/base/net_types.hpp"
#include "net/ip/address.hpp"

namespace net {

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

        void setAddress(const ip::Address &addr);
        void setPort(const portType port);

        ip::Address getAddress() const;
        portType getPort() const;
        sockaddr_type* getData() const;
        protoType getProtocol() const;

        bool isV4() const;
        bool isV6() const;
        
    private:
        union sockTypeData{
            sockaddr_type base;
            sockaddr_v4_type v4;
            sockaddr_v6_type v6;
        } data_;
};

} // namespace net

#endif