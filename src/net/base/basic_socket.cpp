#include "net/base/basic_socket.hpp"

namespace net {

template<class Proto>
BasicSocket<Proto>::BasicSocket() {}

template<class Proto>
BasicSocket<Proto>::~BasicSocket() {
    ::close(fd_);
}

template<class Proto>
void BasicSocket<Proto>::open() {}

template<class Proto>
void BasicSocket<Proto>::close() {
    ::close(fd_);
}

} // namespace net