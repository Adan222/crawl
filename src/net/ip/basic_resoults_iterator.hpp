#ifndef NET_DNS_BASIC_RESOULTS_ITERATOR
#define NET_DNS_BASIC_RESOULTS_ITERATOR

#include <cstddef>
#include <vector>

#include "net/base/basic_endpoint.hpp"

namespace net::ip {

// Forward declaration
template<typename Proto>
class BasicResoultsIterator;

// Friend functions
template<typename Proto>
bool operator==
    (const BasicResoultsIterator<Proto> &a, 
     const BasicResoultsIterator<Proto> &b);
template<typename Proto>
bool operator!=
    (const BasicResoultsIterator<Proto> &a,
     const BasicResoultsIterator<Proto> &b);

template<typename Proto>
class BasicResoultsIterator {
    public:
        using endpoint = BasicEndpoint<Proto>;
        using vectorType = std::vector<endpoint>;

        BasicResoultsIterator();
        ~BasicResoultsIterator();

        // copy constructor
        BasicResoultsIterator(const BasicResoultsIterator &other);

        BasicResoultsIterator& operator++();
        BasicResoultsIterator operator++(int);

        const endpoint& operator*() const;
        const endpoint* operator->() const;

        friend bool operator==<>
            (const BasicResoultsIterator &a, 
             const BasicResoultsIterator &b);

        friend bool operator!=<>
            (const BasicResoultsIterator &a, 
             const BasicResoultsIterator &b);

    protected:
        bool equal(const BasicResoultsIterator &other) const;

        vectorType data_;
        size_t index_;
};

} // namespace net::ip
#endif // NET_DNS_BASIC_RESOULTS_ITERATOR