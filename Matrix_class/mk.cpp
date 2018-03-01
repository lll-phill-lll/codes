#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

template <typename T>
class Matrix {
 private:
    vector<vector<T> > data;

 public:
    Matrix(const vector<vector<T>>& d)
    : data(d) {
    }

    const T& operator() (size_t i, size_t j) const {
        return data[i][j];
    }

    T& operator() (size_t i, size_t j) {
        return data[i][j];
    }

    std::pair<size_t, size_t> size() const {
        return std::pair<size_t, size_t> (data.size(), data[0].size());
    }

    Matrix& operator += (const Matrix& other) {
        for (size_t i = 0; i != data.size(); ++i)
            for (size_t j = 0; j != data[0].size(); ++j)
                data[i][j] += other.data[i][j];
        return *this;
    }

    Matrix operator + (const Matrix& other) const {
        auto C = *this;
        C += other;
        return C;
    }

    template <typename M>
    Matrix& operator *= (const M& other) {
        for (size_t i = 0; i != data.size(); ++i)
            for (size_t j = 0; j != data[0].size(); ++j)
                data[i][j] *= other;
        return *this;
    }

    template <typename M>
    Matrix operator * (const M& other) const {
        auto C = *this;
        C *= other;
        return C;
    }

    Matrix operator * (const Matrix& other) {
        vector<vector<T>> new_m((*this).size().first, vector<T>(other.size().second, 0));
        Matrix<T> new_mat = Matrix<T>(new_m);
        for (size_t i = 0; i != this -> size().first; ++i) {
            for (size_t j = 0; j != other.size().second; ++j) {
                for (size_t p = 0; p != this -> size().second; ++p) {
                    new_mat(i, j) += (*this)(i, p) * other(p, j);
                }
            }
        }
        *this = new_mat;
        return *this;
    }

    Matrix operator *= (const Matrix& other) {
        vector<vector<T>> new_m((*this).size().first, vector<T>(other.size().second, 0));
        Matrix<T> new_mat = Matrix<T>(new_m);
        new_mat = *this * other;
        return new_mat;
    }

    Matrix& transpose() {
        vector<vector<T>> new_m(size().second, vector<T>(size().first, 0));
        Matrix<T> new_mat = Matrix<T>(new_m);
        for (size_t i = 0; i != this -> size().first; ++i)
            for (size_t j = 0; j != this -> size().second; ++j) {
                new_mat(j, i) = (*this)(i, j);
            }
            *this = new_mat;
        return *this;
    }

    Matrix transposed() const {
        Matrix m = *this;
        m.transpose();
        return m;
    }
};


template <typename T>
std::ostream& operator << (std::ostream& out, const Matrix<T>& mat) {
    for (size_t i = 0; i != mat.size().first; ++i) {
        for (size_t j = 0; j != mat.size().second; ++j) {
            out << mat(i, j);
            if (j != mat.size().second - 1) {
                out << "\t";
            }
        }
        if (i != mat.size().first - 1) {
            out << endl;
        }
    }
    return out;
}

int main() {
    Matrix<int> First_matrix;

}
