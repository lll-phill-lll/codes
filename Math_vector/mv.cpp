#include <iostream>
#include <vector>

template <typename T>
class MathVector {
 private:
    std::vector<T> data;

 public:
    // Zero vector of size n
    MathVector(size_t n): data(n) {
    }

    /* MathVector(size_t n) {
        for (size_t i = 0; i != n; ++i) {
            data.push_back(0);
        }
    } */
    template <typename Iter>
    MathVector(Iter first, Iter last) {
        while (first != last) {
            data.push_back(*first);
            ++first;
        }
    }

    size_t Dimension() const {
         return data.size();
    }

    T& operator[] (size_t i) {
        return data[i];
    }

    const T& operator[] (size_t i) const {
        return data[i];
    }
};

template <typename T>
std::ostream& operator << (std::ostream& out, const MathVector<T>& v) {
    out << '(';
    for (size_t i = 0; i != v.Dimension(); ++i) {
        if (i > 0)
            out << ", ";
        out << v[i];
    }
    out << ')';
    return out;
}

template <typename T>
MathVector<T>& operator *= (MathVector<T>& v, const T& scalar) {
    for (size_t i = 0; i != v.Dimension(); ++i)
        v[i] *= scalar;
    return v;
}

template <typename T>
MathVector<T> operator * (const MathVector<T>& v, const T& scalar) {
    auto tmp(v);
    tmp *= scalar;
    return tmp;
}

template <typename T>
MathVector<T> operator * (const T& scalar, const MathVector<T>& v) {
    return v * scalar;
}

template <typename T>
MathVector<T>& operator += (MathVector<T>& u, const MathVector<T>& v) {
    for (size_t i = 0; i != u.Dimension(); ++i)
        u[i] += v[i];
    return u;
}

template <typename T>
MathVector<T> operator + (const MathVector<T>& u, const MathVector<T>& v) {
    auto tmp(u);
    tmp += v;
    return tmp;
}

template <typename T>
int operator , (const MathVector<T>& u, const MathVector<T>& v) {
    int sum = 0;
    for (size_t i = 0; i != u.Dimension(); ++i)
        sum += u[i] * v[i];
    return sum;
}

