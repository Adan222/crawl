#ifndef NET_DNS_RESOLVER_HPP_
#define NET_DNS_RESOLVER_HPP_

#include <cstring>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#include "net/base/net_types.hpp"
#include "net/base/basic_endpoint.hpp"
#include "net/ip/basic_query.hpp"
#include "net/ip/basic_resoults.hpp"

namespace net::ip {

template<typename Proto>
class BasicResolver {
    public:
        typedef Proto protoType;
        typedef typename Proto::endpoint endpoint;
        typedef BasicQuery<Proto> query;
        using resoults = BasicResoults<Proto>;

        BasicResolver();
        ~BasicResolver();

        resoults resolve(const query &q);
};

} // namespace net::ip

#endif // NET_DNS_RESOLVER_HPP_