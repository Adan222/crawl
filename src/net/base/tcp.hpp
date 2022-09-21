#ifndef NET_BASE_TCP_HPP_
#define NET_BASE_TCP_HPP_

#include <sys/socket.h>
#include <netinet/in.h>

#include "net/base/basic_endpoint.hpp"
#include "net/base/basic_socket.hpp"
#include "net/ip/resolver.hpp"

namespace net {

class tcp {
    public:
        using socket = BasicSocket<tcp>;
        using endpoint = BasicEndpoint<tcp>;
        using resolver = ip::BasicResolver<tcp>;

        static tcp v4() noexcept;
        static tcp v6() noexcept;
        
        // return socket type i.e. SOCK_STREAM
        // or SOCK_DGRAM
        int sockType() const;

        // return protocol type i.e. TCP
        // or UDP
        int proto() const;

        // return AF_INET or AF_INET6
        int family() const;

        friend bool operator==(const tcp &a, const tcp &b);
        friend bool operator!=(const tcp &a, const tcp &b);

    private:
        explicit tcp(int af);

        int af_;
};

} // namespace net

#endif // NET_BASE_TCP_HPP_