#pragma once

#include <string>

#include "core/custom/CustomString.h"

namespace custom {

inline std::string toStdString(const CustomString &value) {
    if (value.isEmpty()) return std::string();
    return std::string(value.cStr(), static_cast<std::string::size_type>(value.length()));
}

inline CustomString fromStdString(const std::string &value) {
    if (value.empty()) return CustomString();
    return CustomString(value.c_str(), static_cast<CustomString::SizeType>(value.size()));
}

}  // namespace custom
