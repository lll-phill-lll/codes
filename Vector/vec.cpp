#include <iostream>
#include <vector>
#include <memory>
#include <cstddef>

class Vector {
 private:
     int * data;
     size_t sz = 0;
     size_t cp = 0;

 public:
    Vector() {
        // std::cout << "constructed\n";
    }
    Vector(const Vector& other) {
        data = new int[other.sz];
        for (size_t i = 0; i != other.sz; ++i) {
            data[i] = other.data[i];
        }
        sz = other.sz;
        cp = other.cp;
        // std::cout << "constructed\n";
    }
    void push_back(const int elem) {
        if (cp < sz + 1) {
            int* new_data = new int[sz * 2 + 1];
            for (size_t i = 0; i != sz; ++i) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            cp = sz * 2 + 1;
        }
        data[sz] = elem;
        ++sz;
    }

    void pop_back() {
        --sz;
    }
    size_t size() {
        return sz;
    }

    int operator[](size_t n) {
        return data[n];
    }

    void operator = (const Vector& other) {
        int* new_data = new int[other.sz];
        for (size_t i = 0; i != other.sz; ++i) {
            new_data[i] = other.data[i];
        }
        delete[] data;
        data = new_data;
        sz = other.sz;
        cp = other.cp;
    }
    ~Vector() {
        delete[] data;
    }
};

