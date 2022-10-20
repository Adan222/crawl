#ifndef BASE_ERROR_HPP_
#define BASE_ERROR_HPP_

#include <exception>
#include <system_error>

#include <netdb.h>

namespace error {

void throwError(const std::error_code &ec);

// shouldn`t be static?
template<typename Exception>
void throwException(const Exception &e);

void getLastError(std::error_code &ec);

/**
 * Translate getaddrinfo() error and convert to error_code
 *
 * @param err error code returned by getaddrinfo()
 * @return appropriate error_code
 *
 * NOTE: Should this function be here?
 */
std::error_code translateAddrInfoError(const int err);

} // namespace error

#endif // BASE_ERROR_HPP_