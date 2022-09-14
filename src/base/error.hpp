#ifndef BASE_ERROR_HPP_
#define BASE_ERROR_HPP_

#include <exception>
#include <system_error>

namespace error {

void throwError(const std::error_code &ec);
void throwException(const std::exception &e);
void getLastError(std::error_code &ec);

} // namespace error

#endif // BASE_ERROR_HPP_