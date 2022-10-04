#pragma once

#include <cstddef>
#include <type_traits>

#include "base/buffer/concept.hpp"

// NOTE: I know that we use convention
// one .hpp and .cpp file, but as this
// is(or will be) well templated, I decited
// to do it this way.  

namespace utils {

// Base class to any kind of buffer.
template<typename P>
class BaseBuffer {
    public:
        using pointerType = P;
        using sizeType = std::size_t;

        // Default constructor
        constexpr BaseBuffer() {}

        constexpr BaseBuffer(pointerType data, sizeType size) :
            data_(data),
            size_(size)
        {}

        // C style array
        template<typename T, size_t N>
        constexpr BaseBuffer(const T (&data)[N]) :
            BaseBuffer(static_cast<pointerType>(data), N - 1)
        {}

        constexpr pointerType data() const {
            return data_;
        }

        constexpr sizeType size() const {
            return size_;
        }

        constexpr bool empty() const {
            return size_ == 0;
        }

        // Convert to any type(haven`t been tested well yet)
        // Doesn`t work with std::vector.
        // If you want convert to POD types
        // use bufferCast<>()
        template<typename T>
        constexpr operator T() const {
            const auto data = static_cast<dataPointer<T>>(data_);
            return T(data, size_);
        }

    protected:
        pointerType data_;
        sizeType size_;
};

} // namespace utils
