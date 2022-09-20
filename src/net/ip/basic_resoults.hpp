#ifndef NET_DNS_BASIC_RESOULTS_HPP_
#define NET_DNS_BASIC_RESOULTS_HPP_

#include "net/base/basic_endpoint.hpp"
#include "net/base/net_types.hpp"
#include "net/ip/basic_resoults_iterator.hpp"

namespace net::ip {

// Forward declaration
template<typename Proto>
class BasicResoults;

// Friend functions
template<typename Proto>
bool operator==(const BasicResoults<Proto> &a,
    const BasicResoults<Proto> &b);

template<typename Proto>
bool operator!=(const BasicResoults<Proto> &a,
    const BasicResoults<Proto> &b);

// This class represens resoults of address resolving.
// You can iterate through object of this class and get
// all resolved endpoints.
template<typename Proto>
class BasicResoults : public
    BasicResoultsIterator<Proto>
{
    public:
        using endpoint = typename Proto::endpoint;
        using vectorType = std::vector<endpoint>;

        BasicResoults();
        ~BasicResoults();

        // copy constructor
        BasicResoults(const BasicResoults &other);

        friend bool operator==<>(const BasicResoults<Proto> &a,
            const BasicResoults<Proto> &b);

        friend bool operator!=<>(const BasicResoults<Proto> &a,
            const BasicResoults<Proto> &b);

        static BasicResoults create(addrinfo_type *addr);
};

} // namespace net::ip

#endif // NET_DNS_BASIC_RESOULTS_HPP_