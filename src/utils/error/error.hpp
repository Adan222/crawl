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

} // namespace error

#endif // BASE_ERROR_HPP_