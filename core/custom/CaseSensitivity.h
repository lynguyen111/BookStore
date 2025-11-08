#pragma once

namespace custom {

enum class CaseSensitivity {
    Sensitive,
    Insensitive
};

inline CaseSensitivity sensitive() {
    return CaseSensitivity::Sensitive;
}

inline CaseSensitivity insensitive() {
    return CaseSensitivity::Insensitive;
}

}  // namespace custom
