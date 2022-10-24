#pragma once

#include <string>
#include <sstream>

#include <cstring>

#include "net/ip/concept.hpp"
#include "net/base/net_types.hpp"

namespace net::ip {

/**
 * Query type for any address resolving
 */
template<typename internetProtocol>
class BasicQuery {
    public:
        typedef typename internetProtocol::endpoint endpoint;

        /* Create empty query */
        BasicQuery() :
            hint_(), hostName_(), serviceName_()
        {
            ::memset(&hint_, 0, sizeof(addrinfo_type));
        }

        BasicQuery(const std::string &host) :
            hostName_(host),
            serviceName_("")
        {
            createEmptyHint();
        }


        /**
         * Create query to resolve
         *
         * @param host hostname or domain to resolve
         * @param port or service which help with resolving.
         * Port is set by default.
         * 
         * @param ip   sepcific internet protocol, default is
         * set to unspecify. It means that resolver will return 
         * both ipv4 and ipv6 address.
         */
        template<typename T>
        BasicQuery(const std::string &host,
            const T &port = kDefaultPort, 
            internetProtocol ip = internetProtocol::unspec()
        ) :
            hostName_(host),
            serviceName_(toString(port))
        {
            createEmptyHint();
            hint_.ai_family = ip.family();
        }

        ~BasicQuery() {};

        const addrinfo_type& getHint() const {
            return hint_;
        }

        std::string getHostName() const {
            return hostName_;
        }

        /**
         * Get service name
         *
         * @return service name, or nullptr if serviceName_ is empty
         *
         * NOTE: Does it matter if we return nullptr or empty string?
         */
        const char* getServiceName() const {
            return serviceName_.empty() || serviceName_ == "" ? 
                nullptr : serviceName_.c_str();
        }

    private:
        static constexpr int kDefaultPort = 80;
        
        /**
         * Convert type to std::string
         *
         * If type is integral convert it to std::string,
         * if it`s std::string, return it.
         *
         * @param data template type which we convert to std::string
         * @return converted std::string
         */
        template<typename T>
        inline const std::string toString(const T &data) {
            // That`s cleaver 
            std::ostringstream ss;
            ss << data;
            return ss.str();
        }

        inline constexpr void createEmptyHint() {
            using transportProto = internetProtocol;
            typename transportProto::endpoint endpoint;

            ::memset(&hint_, 0, sizeof(addrinfo_type));
            hint_.ai_family = AF_UNSPEC;
            hint_.ai_socktype = endpoint.getProtocol().sockType();
            hint_.ai_protocol = endpoint.getProtocol().proto();
            hint_.ai_flags = AI_PASSIVE;
        }

        addrinfo_type hint_;
        std::string hostName_;
        std::string serviceName_;
};

} // namespace net::ip
