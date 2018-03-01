#include <iostream>
#include <vector>
#include <tuple>
#include <memory>
#include <cstddef>

using std::make_tuple;
template <typename T, class Deleter = std::default_delete<T>>
class UniquePtr {
 private:
    std::tuple<T*, Deleter> ptr;

 public:
    // constructors
    UniquePtr() {
        ptr = make_tuple(nullptr, Deleter());
    }

    explicit UniquePtr(T * src) {
        ptr = make_tuple(src, Deleter());
    }

    explicit UniquePtr(UniquePtr&& tmp) {
        ptr = make_tuple(tmp.release(), tmp.get_deleter());
    }
    UniquePtr(T * src, const Deleter& del) {
        ptr = make_tuple(src, del);
    }
    // get_deleter
    Deleter& get_deleter() {
        return std::get<1>(ptr);
    }
    const Deleter& get_deleter() const {
        return std::get<1>(ptr);
    }

    // operator = delete
    UniquePtr(const UniquePtr&) noexcept = delete;
    void operator = (const UniquePtr&) noexcept = delete;

    // operator = exc
    UniquePtr& operator= (std::nullptr_t) {
        std::get<1>(ptr)(std::get<0>(ptr));
        ptr = make_tuple(nullptr, Deleter());
        return *this;
    }
    UniquePtr& operator = (UniquePtr&& other) {
        std::get<1>(ptr)(std::get<0>(ptr));
        ptr = make_tuple(other.release(), other.get_deleter());
        return *this;
    }
    // deleter
    ~UniquePtr() {
        std::get<1>(ptr)(std::get<0>(ptr));
    }
    T &operator* () const {
        return *std::get<0>(ptr);
    }
    T &operator* () {
        return *std::get<0>(ptr);
    }
    T* operator -> () const {
        return std::get<0>(ptr);
    }
    T* operator -> () {
        return std::get<0>(ptr);
    }
    T *release() {
        T *temp = std::get<0>(ptr);
        std::get<0>(ptr) = nullptr;
        return temp;
    }
    void reset(T * other) {
        std::get<1>(ptr)(std::get<0>(ptr));
        std::get<0>(ptr) = other;
        other = nullptr;
    }
    void swap(UniquePtr &other) {
        auto tmp = ptr;
        ptr = other.ptr;
        other.ptr = tmp;
    }
    T * get() const {
        return std::get<0>(ptr);
    }
    explicit operator bool() const {
        return (std::get<0>(ptr) != nullptr);
    }
};

