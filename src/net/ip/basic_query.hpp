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

        /* Create empty query */
        BasicQuery();

        /* Create query only from hostname */
        BasicQuery(const std::string &host);

        /* Create query with hostname and port */
        BasicQuery(const std::string &host,
            const std::string &service);
        BasicQuery(const std::string &host, portType port);

        ~BasicQuery();

        const addrinfo_type& getHint() const;
        std::string getHostName() const;

        /**
         * Get service name
         *
         * @return service name, or nullptr if serviceName_ is empty
         *
         * NOTE: Does it matter if we return nullptr or empty string?
         */
        const char* getServiceName() const;

    private:
        void createEmptyHint();

        addrinfo_type hint_;
        std::string hostName_;
        std::string serviceName_;
};

} // namespace net::ip

#endif // NET_DNS_BASIC_QUERY_HPP_