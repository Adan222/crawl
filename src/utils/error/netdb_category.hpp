#pragma once

#include <string>
#include <system_error>

#include <netdb.h>

namespace error {

/**
 * All posible errors returned by getaddrinfo()
 */
enum class netdb_errc {
    addr_family = EAI_ADDRFAMILY,
    again       = EAI_AGAIN,
    badflags    = EAI_BADFLAGS,
    fail        = EAI_FAIL,
    family      = EAI_FAMILY,
    memory      = EAI_MEMORY,
    nodata      = EAI_NODATA,
    noname      = EAI_NONAME,
    service     = EAI_SERVICE,
    socktype    = EAI_SOCKTYPE,
    system      = EAI_SYSTEM,
};

/**
 * Error category for netdb
 *
 * Basicly we need this category for handling
 * error with getaddrinfo().
 *
 * NOTE: Probably we should create individual dir
 * in error/ with error code used for net stuff, maybe:
 * utils/error/net
 * 
 * NOTE2: As we write stuff that`s some kind of extension 
 * to standard lib(but it`s only in our project that`s why
 * we contain it in our namespace), we want it to looks like
 * stdlib. That`s why we don`t follow main coding style.
 */
class netdb_category :
    public std::error_category
{
    public:
        netdb_category() = default;

        const char* name() const noexcept override;
        std::string message(int ev) const override;
};

/**
 * Get reference to netdb_category object
 *
 * This function get the reference to the only 
 * object of this class, defined in netdb_category.cpp
 * We should use only this function to get netdb_category.
 *
 * @return netdb_category reference
 */
const std::error_category& netdb_category();

/**
 * Create error_code from netdb_errc
 *
 * @return error_code with appropriate code
 */
std::error_code make_error_code(netdb_errc e);

} // namespace error