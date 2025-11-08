#pragma once

#include <initializer_list>

#include "core/custom/CustomString.h"
#include "core/custom/DynamicArray.h"

namespace custom {

// Lightweight replacement for QStringList backed by DynamicArray<CustomString>.
class StringList {
public:
    typedef DynamicArray<CustomString>::SizeType SizeType;
    typedef CustomString *Iterator;
    typedef const CustomString *ConstIterator;

    StringList() = default;

    StringList(std::initializer_list<CustomString> init) : _items(init) {}

    StringList(const StringList &) = default;
    StringList(StringList &&) noexcept = default;
    StringList &operator=(const StringList &) = default;
    StringList &operator=(StringList &&) noexcept = default;

    SizeType size() const { return _items.size(); }
    SizeType capacity() const { return _items.capacity(); }

    bool isEmpty() const { return _items.isEmpty(); }
    bool empty() const { return _items.empty(); }

    void clear() { _items.clear(); }
    void reserve(SizeType newCapacity) { _items.reserve(newCapacity); }

    void resize(SizeType newSize, const CustomString &value = CustomString()) { _items.resize(newSize, value); }

    CustomString &operator[](SizeType index) { return _items[index]; }
    const CustomString &operator[](SizeType index) const { return _items[index]; }

    CustomString value(SizeType index) const {
        return index < _items.size() ? _items[index] : CustomString();
    }

    CustomString value(SizeType index, const CustomString &defaultValue) const {
        return index < _items.size() ? _items[index] : defaultValue;
    }

    void pushBack(const CustomString &value) { _items.pushBack(value); }
    void pushBack(CustomString &&value) { _items.pushBack(static_cast<CustomString &&>(value)); }

    void push_back(const CustomString &value) { pushBack(value); }
    void push_back(CustomString &&value) { pushBack(static_cast<CustomString &&>(value)); }

    void append(const CustomString &value) { pushBack(value); }
    void append(CustomString &&value) { pushBack(static_cast<CustomString &&>(value)); }

    void popBack() { _items.popBack(); }
    void pop_back() { _items.popBack(); }

    Iterator begin() { return _items.begin(); }
    ConstIterator begin() const { return _items.begin(); }
    ConstIterator cbegin() const { return _items.cbegin(); }

    Iterator end() { return _items.end(); }
    ConstIterator end() const { return _items.end(); }
    ConstIterator cend() const { return _items.cend(); }

    CustomString &front() { return _items.front(); }
    const CustomString &front() const { return _items.front(); }

    CustomString &back() { return _items.back(); }
    const CustomString &back() const { return _items.back(); }

    CustomString *data() { return _items.data(); }
    const CustomString *data() const { return _items.data(); }

private:
    DynamicArray<CustomString> _items;
};

}  // namespace custom
