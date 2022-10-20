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
        using iterator = typename vectorType::iterator;
        using const_iterator = typename vectorType::const_iterator;

        /* Create empty iterator */
        BasicResoultsIterator();
        ~BasicResoultsIterator();

        /* Copy constructor */
        BasicResoultsIterator(const BasicResoultsIterator &other);

        BasicResoultsIterator& operator++();
        BasicResoultsIterator operator++(int);

        /**
         * Dereference and access operator
         */
        const endpoint& operator*() const;
        const endpoint* operator->() const;

        endpoint operator[](int i) const;

        /* Iterators */
        const_iterator begin() const;
        const_iterator end() const;

        const_iterator cbegin() const;
        const_iterator cend() const;


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