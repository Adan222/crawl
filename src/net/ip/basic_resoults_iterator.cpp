#include "net/ip/basic_resoults_iterator.hpp"
#include "net/base/tcp.hpp"

namespace net::ip {

template<typename Proto>
BasicResoultsIterator<Proto>::BasicResoultsIterator() :
    data_(),
    index_(0)
{}

template<typename Proto>
BasicResoultsIterator<Proto>::~BasicResoultsIterator() {}

template<typename Proto>
BasicResoultsIterator<Proto>
    ::BasicResoultsIterator(const BasicResoultsIterator &other) :
    data_(other.data_),
    index_(other.index_)
{}

template<typename Proto>
BasicResoultsIterator<Proto>&
    BasicResoultsIterator<Proto>::operator++() 
{
    if(index_++ == data_.size())
        index_ = 0;
    else
        index_++;
    return *this;
}

template<typename Proto>
BasicResoultsIterator<Proto>
    BasicResoultsIterator<Proto>::operator++(int) 
{
    BasicResoultsIterator<Proto> tmp = *this;
    ++*this;
    return tmp;
}

template<typename Proto>
const BasicEndpoint<Proto>&
    BasicResoultsIterator<Proto>::operator*() const 
{
    return data_[index_];
}

template<typename Proto>
const BasicEndpoint<Proto>*
    BasicResoultsIterator<Proto>::operator->() const 
{
    return &data_[index_];
}

template<typename Proto>
BasicEndpoint<Proto> BasicResoultsIterator<Proto>::operator[](int i) const {
    return data_.at(i);
}

template<typename Proto>
typename BasicResoultsIterator<Proto>::const_iterator
    BasicResoultsIterator<Proto>::begin() const
{
    return this->data_.begin();
}

template<typename Proto>
typename BasicResoultsIterator<Proto>::const_iterator
    BasicResoultsIterator<Proto>::end() const
{
    return this->data_.end();
}

template<typename Proto>
typename BasicResoultsIterator<Proto>::const_iterator
    BasicResoultsIterator<Proto>::cbegin() const 
{
    return this->data_.cbegin();
}


template<typename Proto>
typename BasicResoultsIterator<Proto>::const_iterator
    BasicResoultsIterator<Proto>::cend() const 
{
    return this->data_.cend();
}


template<typename Proto>
bool operator==
    (const BasicResoultsIterator<Proto> &a, 
     const BasicResoultsIterator<Proto> &b)
{
    return a.equal(b);
}

template<typename Proto>
bool operator!=
    (const BasicResoultsIterator<Proto> &a, 
     const BasicResoultsIterator<Proto> &b)
{
    return !a.equal(b);
}

template<typename Proto>
bool BasicResoultsIterator<Proto>
    ::equal(const BasicResoultsIterator &other) const
{
    if(data_.size() != other.data_.size())
        return false;
    
    for(int i = 0; i < data_.size(); i++)
        if(data_[i] != other.data_[i])
            return false;

    return true;
}

template class BasicResoultsIterator<tcp>;
template bool operator==
    (const BasicResoultsIterator<tcp> &a, 
     const BasicResoultsIterator<tcp> &b);

template bool operator!=
    (const BasicResoultsIterator<tcp> &a, 
     const BasicResoultsIterator<tcp> &b);

} // namespace net::ip