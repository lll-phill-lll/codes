#include <iostream>
#include <vector>
#include <memory>
#include <cstddef>

template <typename T>
class UniquePtr {
 private:
    T *ptr;

 public:
    UniquePtr()
            :ptr(nullptr) {
    }

    explicit UniquePtr(T * src) : ptr(src) {
        src = nullptr;
    }

    explicit UniquePtr(UniquePtr&& tmp) : ptr(tmp.ptr) {
        tmp.ptr = nullptr;
    }

    UniquePtr(const UniquePtr&) noexcept = delete;
    void operator = (const UniquePtr&) noexcept = delete;
    UniquePtr& operator= (std::nullptr_t) {
        ptr = nullptr;
        return *this;
    }
    UniquePtr& operator = (UniquePtr&& other) {
        delete ptr;
        ptr = other.ptr;
        other.ptr = nullptr;
        return *this;
    }
    ~UniquePtr() {
        delete ptr;
    }
    T &operator* () const {
        return *ptr;
    }
    T &operator* () {
        return *ptr;
    }
    T* operator -> () const {
        return ptr;
    }
    T* operator -> () {
        return ptr;
    }
    T *release() {
        T *temp = ptr;
        ptr = nullptr;
        return temp;
    }
    void reset(T * other) {
        delete ptr;
        ptr = other;
    }
    void swap(UniquePtr &other) {
        auto tmp = ptr;
        ptr = other.ptr;
        other.ptr = tmp;
    }
    T * get() const {
        return ptr;
    }
    explicit operator bool() const {
        return (ptr != nullptr);
    }
};

