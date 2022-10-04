#pragma once

#include "base/buffer/base_buffer.hpp"
#include "base/buffer/concept.hpp"
#include <cstddef>

namespace utils {

class ConstBuffer :
    public BaseBuffer<const void*>
{
    public:
        using pointerType = const void*;
        
        // Createing empty const buffer is useless
        ConstBuffer() = delete;

        // Create from raw bytes
        constexpr ConstBuffer(pointerType data, sizeType size) :
            BaseBuffer(data, size)
        {}

        // Create ConstBuffer from some kind of container
        template<typename T>
        constexpr ConstBuffer(const T &type) :
            BaseBuffer(static_cast<pointerType>(std::data(type)), containerDataSize(type))
        {}
};

// Cast to POD type
template<typename podType>
inline podType bufferCast(const ConstBuffer &buff) {
    return static_cast<podType>(buff.data());
}

} // namespace utils
