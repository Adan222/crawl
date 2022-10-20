#include "utils/error/netdb_category.hpp"

namespace error {

const char* netdb_category::name() const noexcept {
    return "netdb";
}

std::string netdb_category::message(int ev) const {
    // TODO: Better error message here
    switch (static_cast<netdb_errc>(ev)) {
        case netdb_errc::eai_addr_family:
            return "eai_addr_family"; break;

        case netdb_errc::eai_family:
            return "eai_family"; break;

        case netdb_errc::eai_again:
            return "eai_again"; break;

        case netdb_errc::eai_fail:
            return "eai_fail"; break;

        case netdb_errc::eai_system:
            return "eai_system"; break;

        case netdb_errc::eai_badflags:
            return "eai_badflags"; break;

        case netdb_errc::eai_memory:
            return "eai_memory"; break;

        case netdb_errc::eai_nodata:
            return "eai_nodata"; break;

        case netdb_errc::eai_noname:
            return "eai_noname"; break;

        case netdb_errc::eai_service:
            return "eai_service"; break;

        case netdb_errc::eai_socktype:
            return "eai_socktype"; break;
        default:
            return "unknow error"; break;
    }
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