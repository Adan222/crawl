#include "utils/error/error.hpp"
#include <system_error>

namespace error {

void throwError(const std::error_code &ec) {
    std::system_error err(ec);
    throwException(err);
}

template<typename Exception>
void throwException(const Exception &e) {
    throw e;
}

void getLastError(std::error_code &ec) {
    ec = std::error_code(errno, std::system_category());
}

} // namespace error