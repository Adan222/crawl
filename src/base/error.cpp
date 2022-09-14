#include "base/error.hpp"
#include <system_error>

namespace error {

void throwError(const std::error_code &ec) {
    std::system_error err(ec);
    throwException(err);
}

void throwException(const std::exception &e) {
    throw e;
}

void getLastError(std::error_code &ec) {
    ec = std::error_code(errno, std::system_category());
}

} // namespace error