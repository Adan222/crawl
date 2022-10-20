#include "utils/error/error.hpp"
#include "utils/error/netdb_category.hpp"

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

std::error_code translateAddrInfoError(const int err) {
    return error::make_error_code(static_cast<netdb_errc>(err));
}

} // namespace error