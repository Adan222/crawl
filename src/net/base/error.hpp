#ifndef NET_BASE_ERROR_HPP_
#define NET_BASE_ERROR_HPP_

#include <system_error>

namespace net {

typedef std::error_code error_code;
typedef std::system_error system_error;
typedef std::errc basic_error;

} // namespace net

#endif // NET_BASE_ERROR_HPP_