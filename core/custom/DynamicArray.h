#pragma once

#include <initializer_list>

namespace custom {

// Manual dynamic array supporting automatic growth without relying on STL containers.
template <typename T>
class DynamicArray {
public:
    typedef unsigned int SizeType;

    typedef T *Iterator;
    typedef const T *ConstIterator;

    DynamicArray() : _data(0), _size(0), _capacity(0) {}

    explicit DynamicArray(SizeType initialSize, const T &value = T()) : _data(0), _size(0), _capacity(0) {
        if (initialSize > 0U) {
            reserve(initialSize);
            for (SizeType i = 0; i < initialSize; ++i) {
                _data[i] = value;
            }
            _size = initialSize;
        }
    }

    DynamicArray(std::initializer_list<T> init) : _data(0), _size(0), _capacity(0) {
        reserve(static_cast<SizeType>(init.size()));
        for (const auto &value : init) {
            pushBack(value);
        }
    }

    DynamicArray(const DynamicArray &other) : _data(0), _size(0), _capacity(0) {
        copyFrom(other);
    }

    DynamicArray &operator=(const DynamicArray &other) {
        if (this != &other) {
            clear();
            copyFrom(other);
        }
        return *this;
    }

    DynamicArray(DynamicArray &&other) noexcept : _data(other._data), _size(other._size), _capacity(other._capacity) {
        other._data = 0;
        other._size = 0U;
        other._capacity = 0U;
    }

    DynamicArray &operator=(DynamicArray &&other) noexcept {
        if (this != &other) {
            destroy();
            _data = other._data;
            _size = other._size;
            _capacity = other._capacity;
            other._data = 0;
            other._size = 0U;
            other._capacity = 0U;
        }
        return *this;
    }

    ~DynamicArray() {
        destroy();
    }

    T &operator[](SizeType index) {
        return _data[index];
    }

    const T &operator[](SizeType index) const {
        return _data[index];
    }

    void pushBack(const T &value) {
        ensureCapacity(_size + 1U);
        _data[_size] = value;
        ++_size;
    }

    void pushBack(T &&value) {
        ensureCapacity(_size + 1U);
        _data[_size] = static_cast<T &&>(value);
        ++_size;
    }

    void push_back(const T &value) {
        pushBack(value);
    }

    void push_back(T &&value) {
        pushBack(static_cast<T &&>(value));
    }

    void append(const T &value) {
        pushBack(value);
    }

    void append(T &&value) {
        pushBack(static_cast<T &&>(value));
    }

    void popBack() {
        if (_size > 0U) {
            --_size;
        }
    }

    void pop_back() {
        popBack();
    }

    void removeAt(SizeType index) {
        if (index >= _size) {
            return;
        }
        for (SizeType i = index; i + 1U < _size; ++i) {
            _data[i] = _data[i + 1U];
        }
        --_size;
    }

    Iterator erase(Iterator position) {
        if (!position || position < _data || position >= _data + _size) {
            return end();
        }
        SizeType index = static_cast<SizeType>(position - _data);
        removeAt(index);
        return _data + index;
    }

    Iterator erase(Iterator first, Iterator last) {
        if (!first || !last || first >= last) {
            return end();
        }
        if (first < _data) {
            first = _data;
        }
        if (last > _data + _size) {
            last = _data + _size;
        }
        SizeType startIndex = static_cast<SizeType>(first - _data);
        SizeType endIndex = static_cast<SizeType>(last - _data);
        SizeType count = endIndex - startIndex;
        for (SizeType i = startIndex; i + count < _size; ++i) {
            _data[i] = _data[i + count];
        }
        _size -= count;
        return _data + startIndex;
    }

    void clear() {
        _size = 0U;
    }

    void reserve(SizeType newCapacity) {
        if (newCapacity <= _capacity) {
            return;
        }
        reallocate(newCapacity);
    }

    void resize(SizeType newSize, const T &value = T()) {
        if (newSize > _capacity) {
            reallocate(newSize);
        }
        if (newSize > _size) {
            for (SizeType i = _size; i < newSize; ++i) {
                _data[i] = value;
            }
        }
        _size = newSize;
    }

    SizeType size() const {
        return _size;
    }

    SizeType capacity() const {
        return _capacity;
    }

    bool empty() const {
        return _size == 0U;
    }

    bool isEmpty() const {
        return _size == 0U;
    }

    T *data() {
        return _data;
    }

    const T *data() const {
        return _data;
    }

    Iterator begin() {
        return _data;
    }

    ConstIterator begin() const {
        return _data;
    }

    ConstIterator cbegin() const {
        return _data;
    }

    Iterator end() {
        return _data ? _data + _size : 0;
    }

    ConstIterator end() const {
        return _data ? _data + _size : 0;
    }

    ConstIterator cend() const {
        return _data ? _data + _size : 0;
    }

    T &front() {
        return _data[0];
    }

    const T &front() const {
        return _data[0];
    }

    T &back() {
        return _data[_size - 1U];
    }

    const T &back() const {
        return _data[_size - 1U];
    }

    const T &value(SizeType index, const T &defaultValue) const {
        return index < _size ? _data[index] : defaultValue;
    }

private:
    void ensureCapacity(SizeType needed) {
        if (needed <= _capacity) {
            return;
        }
        SizeType newCapacity = _capacity == 0U ? 4U : _capacity * 2U;
        if (newCapacity < needed) {
            newCapacity = needed;
        }
        reallocate(newCapacity);
    }

    void copyFrom(const DynamicArray &other) {
        if (other._size == 0U) {
            destroy();
            return;
        }
        reallocate(other._size);
        for (SizeType i = 0; i < other._size; ++i) {
            _data[i] = other._data[i];
        }
        _size = other._size;
    }

    void reallocate(SizeType newCapacity) {
        T *newData = new T[newCapacity];
        for (SizeType i = 0; i < _size; ++i) {
            newData[i] = _data[i];
        }
        delete[] _data;
        _data = newData;
        _capacity = newCapacity;
    }

    void destroy() {
        delete[] _data;
        _data = 0;
        _size = 0U;
        _capacity = 0U;
    }

    T *_data;
    SizeType _size;
    SizeType _capacity;
};

} // namespace custom
