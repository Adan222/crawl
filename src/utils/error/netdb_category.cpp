#include "utils/error/netdb_category.hpp"

namespace error {

const char* netdb_category::name() const noexcept {
    return "netdb";
}

std::string netdb_category::message(int ev) const {
    return ::gai_strerror(ev);
}

// Here we create the only object of netdb_category
static class netdb_category netdb_category_obj{};
const std::error_category& netdb_category() {
    return netdb_category_obj;
}

std::error_code make_error_code(netdb_errc e) {
    return {static_cast<int>(e), netdb_category()};
}

} // namespace error