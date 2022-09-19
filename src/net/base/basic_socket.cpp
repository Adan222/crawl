#include "net/base/basic_socket.hpp"
#include "net/base/tcp.hpp"

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

template class BasicSocket<tcp>;

} // namespace net