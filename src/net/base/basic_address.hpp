#ifndef NET_IP_BASIC_ADDRESS_HPP_
#define NET_IP_BASIC_ADDRESS_HPP_

#include <string>

namespace net {
namespace ip {

class BasicAddress {
    public:
        BasicAddress() {}
        virtual ~BasicAddress() {}

        virtual std::string toString() const = 0;
};

} // namespace ip
} // namespace net

#endif