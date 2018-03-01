#include <deque>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

// memtracer

void go(std::vector<std::vector<int>> &field, std::vector<std::vector<bool>> &been,
              int x, int y) {
        std::queue<std::pair<int, int>> togo;
        std::pair<int, int> current;
        current.first = x;
        current.second = y;
        // been[x][y] = true;
        field[x][y] = 0;
        togo.push(current);
        while (!togo.empty()) {
            current = togo.front();
            togo.pop();
            x = current.first;
            y = current.second;
            been[x][y] = true;
            if (x + 1 < field.size() && y + 2 < field[0].size()) {
                if (been[x + 1][y + 2] == false) {
                    togo.push(std::make_pair(x + 1, y + 2));
                    been[x + 1][y + 2] = true;
                }
                field[x + 1][y + 2] = std::min(field[x + 1][y + 2], field[x][y] + 1);
            }

            if (x + 1 < field.size() && y - 2 > 0) {
                if (been[x + 1][y - 2] == false) {
                    togo.push(std::make_pair(x + 1, y - 2));
                    been[x + 1][y - 2] = true;
                }
                field[x + 1][y - 2] = std::min(field[x + 1][y - 2], field[x][y] + 1);
            }

            if (x - 1 > 0 && y + 2 < field[0].size()) {
                if (been[x - 1][y + 2] == false) {
                    togo.push(std::make_pair(x - 1, y + 2));
                    been[x - 1][y + 2] = true;
                }
                field[x - 1][y + 2] = std::min(field[x - 1][y + 2], field[x][y] + 1);
            }

            if (x - 1 > 0 && y - 2 > 0) {
                if (been[x - 1][y - 2] == false) {
                    togo.push(std::make_pair(x - 1, y - 2));
                    been[x - 1][y - 2] = true;
                }
                field[x - 1][y - 2] = std::min(field[x - 1][y - 2], field[x][y] + 1);
            }

            if (x + 2 < field.size() && y + 1 < field[0].size()) {
                if (been[x + 2][y + 1] == false) {
                    togo.push(std::make_pair(x + 2, y + 1));
                    been[x + 2][y + 1] = true;
                }
                field[x + 2][y + 1] = std::min(field[x + 2][y + 1], field[x][y] + 1);
            }

            if (x + 2 < field.size() && y - 1 > 0) {
                if (been[x + 2][y - 1] == false) {
                    togo.push(std::make_pair(x + 2, y - 1));
                    been[x + 2][y - 1] = true;
                }
                field[x + 2][y - 1] = std::min(field[x + 2][y - 1], field[x][y] + 1);
            }

            if (x - 2 > 0 && y + 1 < field[0].size()) {
                if (been[x - 2][y + 1] == false) {
                    togo.push(std::make_pair(x - 2, y + 1));
                    been[x - 2][y + 1] = true;
                }
                field[x - 2][y + 1] = std::min(field[x - 2][y + 1], field[x][y] + 1);
            }

            if (x - 2 > 0 && y - 1 > 0) {
                if (been[x - 2][y - 1] == false) {
                    togo.push(std::make_pair(x - 2, y - 1));
                    been[x - 2][y - 1] = true;
                }
                field[x - 2][y - 1] = std::min(field[x - 2][y - 1], field[x][y] + 1);
            }
        }
    }

void print(int beg, std::vector<int>& pred, int k, std::vector<int> &result) {
    result.push_back(k);
    if (pred[k] != beg) {
        print(beg, pred, pred[k], result);
    } else {
        result.push_back(pred[k]);
    }
}

void dijkstra(std::vector<std::vector<int>> &table, std::vector<int> &min_len,
               std::vector<bool> &been, std::vector<int> &pred) {
    int m = been.end() - been.begin() + 2;
    auto min_it = been.end();
    int current_number;
    for (auto it = been.begin() + 1; it != been.end(); ++it) {
        current_number = it - been.begin();
        if (*it == false && min_len[current_number] < m) {
            m = min_len[it - been.begin()];
            min_it = it;
        }
    }
    been[min_it - been.begin()] = true;
    for (int i = 1; i != been.size(); ++i) {
        if (table[i][min_it - been.begin()] != 0) {
            min_len[i] = std::min(min_len[i], min_len[min_it - been.begin()] + 1);
            if (std::min(min_len[i], min_len[min_it - been.begin()] + 1)
                == min_len[min_it - been.begin()] + 1) {
                pred[i] = min_it - been.begin();
            }
            // pred[i] = min_it - been.begin();
        }
    }
}

int main() {
    int size_x, size_y;
    std::cin >> size_x >> size_y;
    std::vector<std::vector<int>> field(size_x + 1, std::vector<int>
                                        (size_y + 1, size_x * size_y + 1));
    std::vector<std::vector<bool>> been(size_x + 1, std::vector<bool> (size_y + 1, 0));
    int x, y;
    std::cin >> x >> y;
    field[x][y] = 0;
    go(field, been, x, y);
    /* for (size_t i = 1; i != size_x + 1; ++i) {
        for (size_t j = 1; j != size_y + 1; ++j) {
            std::cout << field[i][j] << '\t';
        }
        std::cout << std::endl;
    } */
    int num;
    std::cin >> num;
    int f, s;
    int sum = 0;
    bool fail = 0;
    for (size_t i = 0; i != num; ++i) {
        std::cin >> f >> s;
        if (been[f][s] == 0) fail = true;
        sum += field[f][s];
    }
    // std::cout << fail << " ";
    if (fail != 0) {
        std::cout << -1;
    } else {
        std::cout << sum;
    }
}

