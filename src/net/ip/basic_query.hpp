#ifndef NET_DNS_BASIC_QUERY_HPP_
#define NET_DNS_BASIC_QUERY_HPP_

#include <string>

#include "net/base/net_types.hpp"

namespace net::ip {

/**
 * Query type for any address resolving
 */
template<typename Proto>
class BasicQuery {
    public:
        typedef Proto ProtoType;
        typedef typename Proto::endpoint endpoint;

        BasicQuery();
        BasicQuery(const std::string &host,
            const std::string &service);

        ~BasicQuery();

        const addrinfo_type& getHint() const;
        std::string getHostName() const;
        std::string getServiceName() const;

    private:
        addrinfo_type hint_;
        std::string hostName_;
        std::string serviceName_;
};

} // namespace net::ip

#endif // NET_DNS_BASIC_QUERY_HPP_