#include "core/String.h"

#include <utility>

namespace pbl2::core {

String::String() = default;

String::String(const char *text) : value_(text) {}

String::String(const char *text, int length) {
    assign(text, length);
}

String::String(const custom::CustomString &value) : value_(value) {}

String::String(custom::CustomString &&value) noexcept : value_(std::move(value)) {}

String::String(const String &other) = default;

String::String(String &&other) noexcept = default;

String::~String() = default;

String &String::operator=(const String &other) = default;

String &String::operator=(String &&other) noexcept = default;

String &String::operator=(const custom::CustomString &value) {
    value_ = value;
    return *this;
}

const char *String::c_str() const { return value_.cStr(); }

const char *String::data() const { return value_.cStr(); }

char *String::data() { return value_.data(); }

int String::size() const { return static_cast<int>(value_.length()); }

bool String::empty() const { return value_.isEmpty(); }

void String::clear() { value_.clear(); }

void String::assign(const char *text) {
    if (!text) {
        value_.clear();
        return;
    }
    value_ = custom::CustomString(text);
}

void String::assign(const char *text, int length) {
    if (!text || length <= 0) {
        value_.clear();
        return;
    }
    value_ = custom::CustomString(text, static_cast<SizeType>(length));
}

String String::trimmed() const { return String(value_.trimmed()); }

String String::upper() const { return String(value_.toUpper()); }

String String::lower() const { return String(value_.toLower()); }

bool String::equalsIgnoreCase(const String &other) const {
    return value_.compare(other.value_, custom::CaseSensitivity::Insensitive) == 0;
}

bool String::operator==(const String &other) const { return value_ == other.value_; }

bool String::operator!=(const String &other) const { return !(*this == other); }

int String::toInt(bool *ok, int base) const { return value_.toInt(ok, base); }

}  // namespace pbl2::core
