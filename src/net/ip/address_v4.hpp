#ifndef NET_IP_ADDRESS_V4_HPP_
#define NET_IP_ADDRESS_V4_HPP_

#include <array>
#include <string>
#include <cstring>

#include <arpa/inet.h>

#include "net/base/net_types.hpp"

namespace net::ip {

// Forward declaration
class AddressV4;

// Friend functions
bool operator==(const AddressV4 &a, const AddressV4 &b);
bool operator!=(const AddressV4 &a, const AddressV4 &b);

/**
 * This class represent address containing ipv4
 */
class AddressV4 {
    public:
        using v4Type = std::uint32_t;
        using v4ByteType = std::array<std::uint8_t, 4>;

        /* Create empty address */
        AddressV4();

        /**
         * Create address from primitive types
         */
        AddressV4(const v4Type addr);
        AddressV4(const v4ByteType &bytes);

        // Shouldn`t we provide this constructor?
        //AddressV4(const uint8_t bytes[4]);

        /**
         * Destructor
         */
        ~AddressV4();
        
        /**
         * Convert address to string
         *
         * @return address as string
         */
        std::string toString() const;

        /**
         * Convert address to 32 bit unsigned integer
         *
         * @return addr_.s_addr which is just uint32_t  
         */
        v4Type toInt() const;

        /**
         * Comapre two addresses
         */
        friend bool operator==(const AddressV4 &a, const AddressV4 &b);
        friend bool operator!=(const AddressV4 &a, const AddressV4 &b);

    private:
        in4_addr_type addr_;
};

namespace V4 {
    /**
     * Create AddressV4 from string
     *
     * @return AddressV4 object
     */
    AddressV4 fromString(const std::string &str);
    AddressV4 fromString(const char *str);

} // namespace V4

} // namespace net::ip

#endif