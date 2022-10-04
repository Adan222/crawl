#pragma once

#include <iterator>
#include <type_traits>

namespace utils {

template<typename T>
using dataPointer = decltype(std::data(std::declval<T>()));

template<typename T>
using dataType = std::iter_value_t<dataPointer<T>>;

template<typename T>
constexpr auto dataTypeSize = sizeof(dataType<T>);

template<typename T>
constexpr auto containerDataSize(const T &type) {
    return std::size(type) * dataTypeSize<T>;
}

} // namespace utils