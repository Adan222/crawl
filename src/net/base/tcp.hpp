#ifndef NET_BASE_TCP_HPP_
#define NET_BASE_TCP_HPP_

#include <sys/socket.h>
#include <netinet/in.h>

#include "net/base/basic_endpoint.hpp"
#include "net/base/basic_socket.hpp"

namespace net {

class tcp {
    public:
        typedef BasicSocket<tcp> socket;
        typedef BasicEndpoint<tcp> endpoint;

        static tcp v4() noexcept;
        static tcp v6() noexcept;

        constexpr int type() const;
        constexpr int proto() const;
        constexpr int family() const;

    private:
        explicit tcp(int af);

        int af_;
};

} // namespace net

#endif // NET_BASE_TCP_HPP_