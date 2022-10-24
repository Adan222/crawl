#pragma once

#include <string>

namespace net::ip {

/**
 * NOTE: Should be used in query, but those concepts 
 * aren`t done yet
 */

template<typename T>
concept cIntegralPortType = 
    (std::is_integral_v<T> &&
     std::is_unsigned_v<T>);

/**
 * NOTE: Maybe there is better way to make
 * this concept as we only check if type is
 * std::string and string literal. But what about
 * others std::basic_strings or string literals.
 */
template<typename T>
concept cStringPortType = 
    (std::is_same_v<T, std::string> || 
     std::is_same_v<T, const char*>);

template<typename T>
concept cPortType = 
    (cIntegralPortType<T> || cStringPortType<T>);

} // namespace net::ip