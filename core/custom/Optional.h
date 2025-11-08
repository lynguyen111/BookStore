#pragma once

namespace custom {

struct NullOptTag {
};

constexpr NullOptTag nullopt{};

template <typename T>
class Optional {
public:
    Optional() : hasValue(false), storage() {}

    Optional(NullOptTag) : hasValue(false), storage() {}

    Optional(const T &value) : hasValue(true), storage(value) {}

    Optional(const Optional &other) : hasValue(other.hasValue), storage() {
        if (other.hasValue) {
            storage = other.storage;
        }
    }

    Optional &operator=(NullOptTag) {
        reset();
        return *this;
    }

    Optional &operator=(const T &value) {
        storage = value;
        hasValue = true;
        return *this;
    }

    Optional &operator=(const Optional &other) {
        if (this != &other) {
            hasValue = other.hasValue;
            if (hasValue) {
                storage = other.storage;
            }
        }
        return *this;
    }

    ~Optional() = default;

    bool has_value() const {
        return hasValue;
    }

    operator bool() const {
        return hasValue;
    }

    void reset() {
        hasValue = false;
    }

    T &value() {
        return storage;
    }

    const T &value() const {
        return storage;
    }

    T &operator*() {
        return storage;
    }

    const T &operator*() const {
        return storage;
    }

    T *operator->() {
        return &storage;
    }

    const T *operator->() const {
        return &storage;
    }

private:
    bool hasValue;
    T storage;
};

template <typename T>
Optional<T> makeOptional(const T &value) {
    return Optional<T>(value);
}

}  // namespace custom
