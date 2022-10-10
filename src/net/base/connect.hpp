#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <memory>

#include "net/base/connection.hpp"
#include "net/base/net_types.hpp"
#include "net/base/functions.hpp"
#include "net/base/stream_socket.hpp"

namespace net {

/**
 * Try connect given socket with endpoint
 *
 * @param sock which socket connect
 * @param end  endpoint where connect
 */
int connSocket
    (const StreamSocket &sock, const tcp::endpoint &end);


/**
 * Create connection using endpoint
 *
 * @param end information where we want to connect
 * @return established connection 
 */
std::unique_ptr<Connection> connect(const tcp::resolver::resoults &res);

} // namespace net