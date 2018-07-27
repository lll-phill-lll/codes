#include <iostream>
#include <vector>
#include <algorithm>


class bin_num {
 private:
    std::vector<int> data;

 public:
    explicit bin_num(size_t n) : data(n, 0) {
    }
    size_t size() const {
        return data.size();
    }

    const int operator[] (size_t i) const {
        return data[i];
    }

    const int operator[] (size_t i) {
        return data[i];
    }

    bool next() {
        int add = 1;
        size_t counter = 0;
        size_t n = data.size();
        for (int i = n - 1; i >= 0; --i) {
            data[i] = data[i] + add;
            if (data[i] == 2) {
                data[i] = 0;
                add = 1;
                ++counter;
            } else {
                add = 0;
            }
        }
        if (counter != n) {
            return true;
        } else {
            return false;
        }
    }
};

std::ostream& operator << (std::ostream& out, const bin_num& number) {
    for (size_t i = 0; i != number.size(); ++i) {
        int t = (number[i]) ? 1 : 2;
        out << t << " ";
    }
    out << std::endl;
    return out;
}

int main() {
    int vertex_number;
    std::cin >> vertex_number;
    std::vector<std::vector<int>> matrix(vertex_number, std::vector<int>(vertex_number));
    for (size_t i = 0; i != vertex_number; ++i) {
        for (size_t j = 0; j != vertex_number; ++j) {
            std::cin >> matrix[i][j];
        }
    }
    bin_num final_permutation(vertex_number);
    bin_num permutations(vertex_number);
    int max_weight = -1;
    while (permutations.next()) {
        int moment_weight = 0;
        for (size_t i = 0; i != vertex_number; ++i) {
            if (permutations[i] == 1) {
                for (size_t j = 0; j != vertex_number; ++j) {
                    if (permutations[j] == 0) {
                        moment_weight += matrix[i][j];
                    }
                }
            }
        }
        if (moment_weight > max_weight) {
            max_weight = moment_weight;
            final_permutation = permutations;
        }
    }
    std::cout << max_weight << std::endl << final_permutation;
    return 0;
}
