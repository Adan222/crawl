#pragma once

#include "utils/buffer/base_buffer.hpp"
#include "utils/buffer/concept.hpp"

namespace utils {

class MutableBuffer :
    public BaseBuffer<void*>
{
    public:
        using pointerType = void*;

        // Empty buffer
        constexpr MutableBuffer() :
            BaseBuffer(nullptr, 0)
        {}

        // Create from raw data
        constexpr MutableBuffer(pointerType data, sizeType size) :
            BaseBuffer(data, size)
        {}

        // Create ConstBuffer from some kind of container
        template<typename T>
        constexpr MutableBuffer(T &&type) :
            BaseBuffer(static_cast<pointerType>(std::data(type)), containerDataSize(type))
        {}
};

// Cast to POD type
template<typename podType>
inline podType bufferCast(const MutableBuffer &buff) {
    return static_cast<podType>(buff.data());
}

} // namespace utils
