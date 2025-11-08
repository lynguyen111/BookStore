#pragma once

#include "core/custom/CaseSensitivity.h"
#include "core/custom/CustomString.h"

namespace pbl2::core {

class String {
public:
    using SizeType = custom::CustomString::SizeType;

    String();
    explicit String(const char *text);
    String(const char *text, int length);
    explicit String(const custom::CustomString &value);
    String(custom::CustomString &&value) noexcept;
    String(const String &other);
    String(String &&other) noexcept;
    ~String();

    String &operator=(const String &other);
    String &operator=(String &&other) noexcept;
    String &operator=(const custom::CustomString &value);

    const char *c_str() const;
    const char *data() const;
    char *data();
    int size() const;
    bool empty() const;

    void clear();
    void assign(const char *text);
    void assign(const char *text, int length);

    String trimmed() const;
    String upper() const;
    String lower() const;

    bool equalsIgnoreCase(const String &other) const;

    bool operator==(const String &other) const;
    bool operator!=(const String &other) const;

    int toInt(bool *ok = nullptr, int base = 10) const;

private:
    custom::CustomString value_;
};

}  // namespace pbl2::core
