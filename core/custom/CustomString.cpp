#include "CustomString.h"

#include <cctype>
#include <cstdlib>
#include <cstring>

namespace custom {

namespace {
constexpr char kEmptyString[] = "";
}  // namespace

CustomString::CustomString() : _data(nullptr), _length(0U), _capacity(0U) {
    reserve(8U);
    _data[0] = '\0';
}

CustomString::CustomString(const char *text) : CustomString() {
    const SizeType textLength = stringLength(text);
    ensureCapacity(textLength + 1U);
    copyCharacters(_data, text, textLength);
    _length = textLength;
    _data[_length] = '\0';
}

CustomString::CustomString(const char *text, SizeType length) : CustomString() {
    if (!text || length == 0U) {
        return;
    }
    ensureCapacity(length + 1U);
    copyCharacters(_data, text, length);
    _length = length;
    _data[_length] = '\0';
}

CustomString::CustomString(const CustomString &other) : CustomString(other._data) {}

CustomString::CustomString(CustomString &&other) noexcept : _data(other._data), _length(other._length), _capacity(other._capacity) {
    other._data = nullptr;
    other._length = 0U;
    other._capacity = 0U;
}

CustomString::~CustomString() {
    delete[] _data;
    _data = nullptr;
    _length = 0U;
    _capacity = 0U;
}

CustomString &CustomString::operator=(const CustomString &other) {
    if (this != &other) {
        ensureCapacity(other._length + 1U);
        copyCharacters(_data, other._data, other._length);
        _length = other._length;
        _data[_length] = '\0';
    }
    return *this;
}

CustomString &CustomString::operator=(CustomString &&other) noexcept {
    if (this != &other) {
        delete[] _data;
        _data = other._data;
        _length = other._length;
        _capacity = other._capacity;
        other._data = nullptr;
        other._length = 0U;
        other._capacity = 0U;
    }
    return *this;
}

const char *CustomString::cStr() const { return _data ? _data : kEmptyString; }

char *CustomString::data() { return _data; }

CustomString::SizeType CustomString::length() const { return _length; }

CustomString::SizeType CustomString::capacity() const { return _capacity; }

void CustomString::clear() {
    _length = 0U;
    if (_data) _data[0] = '\0';
}

void CustomString::reserve(SizeType newCapacity) {
    if (newCapacity <= _capacity) return;
    char *newData = new char[newCapacity];
    if (_data) {
        copyCharacters(newData, _data, _length);
        delete[] _data;
    }
    _data = newData;
    _capacity = newCapacity;
    if (_data) _data[_length] = '\0';
}

void CustomString::pushBack(char value) {
    ensureCapacity(_length + 2U);
    _data[_length++] = value;
    _data[_length] = '\0';
}

void CustomString::popBack() {
    if (_length == 0U) return;
    --_length;
    _data[_length] = '\0';
}

void CustomString::append(const CustomString &other) {
    append(other.cStr());
}

void CustomString::append(const char *text) {
    if (!text) return;
    const SizeType textLength = stringLength(text);
    ensureCapacity(_length + textLength + 1U);
    copyCharacters(_data + _length, text, textLength);
    _length += textLength;
    _data[_length] = '\0';
}

void CustomString::append(const char *text, SizeType length) {
    if (!text || length == 0U) return;
    ensureCapacity(_length + length + 1U);
    copyCharacters(_data + _length, text, length);
    _length += length;
    _data[_length] = '\0';
}

char &CustomString::operator[](SizeType index) { return _data[index]; }

const char &CustomString::operator[](SizeType index) const { return _data[index]; }

int CustomString::compare(const CustomString &other) const { return compare(other, CaseSensitivity::Sensitive); }

int CustomString::compare(const char *text) const {
    return compare(text, CaseSensitivity::Sensitive);
}

int CustomString::compare(const CustomString &other, CaseSensitivity cs) const {
    return compare(other.cStr(), cs);
}

int CustomString::compare(const char *text, CaseSensitivity cs) const {
    if (!text) text = kEmptyString;
    const char *lhs = cStr();
    const char *rhs = text;
    while (*lhs != '\0' && *rhs != '\0') {
        const int diff = charCompare(*lhs, *rhs, cs);
        if (diff != 0) return diff;
        ++lhs;
        ++rhs;
    }
    if (*lhs == '\0' && *rhs == '\0') return 0;
    return (*lhs == '\0') ? -1 : 1;
}

int CustomString::find(const CustomString &needle) const { return find(needle.cStr()); }

int CustomString::find(const char *needle) const {
    if (!needle) return -1;
    const SizeType needleLen = stringLength(needle);
    if (needleLen == 0U || needleLen > _length) return -1;
    for (SizeType i = 0U; i <= _length - needleLen; ++i) {
        SizeType j = 0U;
        while (j < needleLen && _data[i + j] == needle[j]) {
            ++j;
        }
        if (j == needleLen) return static_cast<int>(i);
    }
    return -1;
}

CustomString CustomString::trimmed() const {
    if (_length == 0U) return CustomString();
    SizeType start = 0U;
    while (start < _length && isSpace(_data[start])) {
        ++start;
    }
    if (start == _length) return CustomString();
    SizeType end = _length - 1U;
    while (end > start && isSpace(_data[end])) {
        --end;
    }
    const SizeType newLen = end - start + 1U;
    return CustomString(_data + start, newLen);
}

CustomString CustomString::toLower() const {
    CustomString result;
    result.ensureCapacity(_length + 1U);
    for (SizeType i = 0U; i < _length; ++i) {
        result._data[i] = toLowerChar(_data[i]);
    }
    result._length = _length;
    result._data[result._length] = '\0';
    return result;
}

CustomString CustomString::toUpper() const {
    CustomString result;
    result.ensureCapacity(_length + 1U);
    for (SizeType i = 0U; i < _length; ++i) {
        result._data[i] = toUpperChar(_data[i]);
    }
    result._length = _length;
    result._data[result._length] = '\0';
    return result;
}

bool CustomString::contains(const CustomString &needle, CaseSensitivity cs) const {
    return contains(needle.cStr(), cs);
}

bool CustomString::contains(const char *needle, CaseSensitivity cs) const {
    if (!needle) return false;
    const SizeType needleLen = stringLength(needle);
    if (needleLen == 0U) return true;
    for (SizeType i = 0U; i <= _length - needleLen; ++i) {
        SizeType j = 0U;
        while (j < needleLen && charCompare(_data[i + j], needle[j], cs) == 0) {
            ++j;
        }
        if (j == needleLen) return true;
    }
    return false;
}

bool CustomString::startsWith(const CustomString &prefix, CaseSensitivity cs) const {
    return startsWith(prefix.cStr(), cs);
}

bool CustomString::startsWith(const char *prefix, CaseSensitivity cs) const {
    if (!prefix) return false;
    SizeType index = 0U;
    while (prefix[index] != '\0') {
        if (index >= _length) return false;
        if (charCompare(_data[index], prefix[index], cs) != 0) return false;
        ++index;
    }
    return true;
}

int CustomString::toInt(bool *ok, int base) const {
    if (base < 2 || base > 36) {
        if (ok) *ok = false;
        return 0;
    }
    char *endPtr = nullptr;
    const long value = std::strtol(cStr(), &endPtr, base);
    if (ok) {
        *ok = (endPtr != cStr() && *endPtr == '\0');
    }
    return static_cast<int>(value);
}

const unsigned char *CustomString::bytes() const {
    return reinterpret_cast<const unsigned char *>(cStr());
}

CustomString CustomString::fromUtf8(const char *data, int size) {
    if (!data || size <= 0) return CustomString();
    CustomString result;
    result.ensureCapacity(static_cast<SizeType>(size + 1));
    copyCharacters(result._data, data, static_cast<SizeType>(size));
    result._length = static_cast<SizeType>(size);
    result._data[result._length] = '\0';
    return result;
}

void CustomString::ensureCapacity(SizeType needed) {
    if (needed <= _capacity) return;
    SizeType newCapacity = _capacity == 0U ? 1U : _capacity;
    while (newCapacity < needed) newCapacity *= 2U;
    reserve(newCapacity);
}

CustomString::SizeType CustomString::stringLength(const char *text) {
    if (!text) return 0U;
    SizeType count = 0U;
    while (text[count] != '\0') ++count;
    return count;
}

void CustomString::copyCharacters(char *destination, const char *source, SizeType count) {
    for (SizeType i = 0U; i < count; ++i) destination[i] = source[i];
}

int CustomString::charCompare(char lhs, char rhs, CaseSensitivity cs) {
    if (cs == CaseSensitivity::Insensitive) {
        lhs = toLowerChar(lhs);
        rhs = toLowerChar(rhs);
    }
    const int diff = static_cast<unsigned char>(lhs) - static_cast<unsigned char>(rhs);
    if (diff < 0) return -1;
    if (diff > 0) return 1;
    return 0;
}

bool CustomString::isSpace(char ch) {
    return std::isspace(static_cast<unsigned char>(ch)) != 0;
}

char CustomString::toLowerChar(char ch) {
    return static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
}

char CustomString::toUpperChar(char ch) {
    return static_cast<char>(std::toupper(static_cast<unsigned char>(ch)));
}

} // namespace custom
