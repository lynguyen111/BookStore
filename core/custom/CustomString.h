#pragma once

#include <cstddef>
#include <cstdint>

#include "core/custom/CaseSensitivity.h"

namespace custom {

class CustomString {
public:
    typedef unsigned int SizeType;

    CustomString();
    explicit CustomString(const char *text);
    CustomString(const char *text, SizeType length);
    CustomString(const CustomString &other);
    CustomString(CustomString &&other) noexcept;
    ~CustomString();

    CustomString &operator=(const CustomString &other);
    CustomString &operator=(CustomString &&other) noexcept;

    const char *cStr() const;
    char *data();
    SizeType length() const;
    SizeType capacity() const;
    bool isEmpty() const { return _length == 0U; }

    bool operator==(const CustomString &other) const { return compare(other) == 0; }
    bool operator!=(const CustomString &other) const { return !(*this == other); }

    void clear();
    void reserve(SizeType newCapacity);

    void pushBack(char value);
    void popBack();

    void append(const CustomString &other);
    void append(const char *text);
    void append(const char *text, SizeType length);

    char &operator[](SizeType index);
    const char &operator[](SizeType index) const;

    int compare(const CustomString &other) const;
    int compare(const char *text) const;
    int compare(const CustomString &other, CaseSensitivity cs) const;
    int compare(const char *text, CaseSensitivity cs) const;

    int find(const CustomString &needle) const;
    int find(const char *needle) const;

    CustomString trimmed() const;
    CustomString toLower() const;
    CustomString toUpper() const;

    bool contains(const CustomString &needle, CaseSensitivity cs = CaseSensitivity::Sensitive) const;
    bool contains(const char *needle, CaseSensitivity cs = CaseSensitivity::Sensitive) const;

    bool startsWith(const CustomString &prefix, CaseSensitivity cs = CaseSensitivity::Sensitive) const;
    bool startsWith(const char *prefix, CaseSensitivity cs = CaseSensitivity::Sensitive) const;

    int toInt(bool *ok = nullptr, int base = 10) const;
    const unsigned char *bytes() const;

    static CustomString fromUtf8(const char *data, int size);

private:
    char *_data;
    SizeType _length;
    SizeType _capacity;

    void ensureCapacity(SizeType needed);
    static SizeType stringLength(const char *text);
    static void copyCharacters(char *destination, const char *source, SizeType count);
    static int charCompare(char lhs, char rhs, CaseSensitivity cs);
    static bool isSpace(char ch);
    static char toLowerChar(char ch);
    static char toUpperChar(char ch);
};

inline CustomString CustomStringLiteral(const char *text) { return CustomString(text); }

} // namespace custom
