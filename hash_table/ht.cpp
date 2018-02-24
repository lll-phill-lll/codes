#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <deque>
#include <map>
#include <list>

class hash {
private:
    std::vector<std::list<int>> data;
    int del = 10;
    size_t sz = 0;
    size_t cp = 10;
public:
    hash() {
        data.resize(del);
    }

    void rehash(std::vector<std::list<int>> & a, bool upper) {
        if (upper) {
            std::vector<std::list<int>> b(a.size() * 2);
            del = a.size() * 2;
            for (auto lists : a) {
                for (auto nums : lists) {
                    b[nums % del].push_front(nums);
                }
            }
            a = b;
            cp = del;
        } else {
            std::vector<std::list<int>> b(a.size() / 2);
            int del = a.size() / 2;
            for (auto lists : a) {
                for (auto nums : lists) {
                    b[nums % del].push_front(nums);
                }
            }
            a = b;
            cp = del;
        }
    }

    void insert(int k) {
        if (data[k % del].size() < 5) {
            if (std::find(data[k % del].begin(), data[k % del].end(), k) == data[k % del].end()) {
                data[k % del].push_front(k);
                ++sz;
                if ((cp / 4) * 3 < sz) {
                    rehash(data, 1);
                }
            }
        } else {
            del = del * 2;
            rehash(data, 1);
        }
    }

    size_t size() {
        return sz;
    }

    size_t capacity() {
        return cp;
    }

    std::list<int>::iterator find(int t) {
        auto it = std::find(data[t % del].begin(), data[t % del].end(), t);
        return it;
    }

    void erase(int t) {
        auto it = std::find(data[t % del].begin(), data[t % del].end(), t);
        if (it != data[t % del].end()) {
            data[t % del].erase(it);
            --sz;
        }
        if (sz < cp / 4) {
            rehash(data, 0);
        }
    }
};

int main() {
    hash m;
    std::cout << "There are some available actions:\nInsert num\nErase num\nGet capacity\nGet size\n";
    std::cout << "Enter the operation (example: insert 5, erase 5, capacity, size):\n";
    std::string s;
    int n;
    while (std::cin >> s) {
        if (s == "insert" ) {
            std::cin >> n;
            m.insert(n);
            std::cout << "Something else?\n";
        } else if (s == "erase") {
            std::cin >> n;
            m.erase(n);
            std::cout << "Something else?\n";
        } else if (s == "capacity") {
            std::cout << m.capacity() << std::endl;
            std::cout << "Something else?\n";
        } else if (s == "size") {
            std::cout << m.size() << std::endl;
            std::cout << "Something else?\n";
        } else {
            std::cout << "Wrong command, try again :(\n";
        }
    }
    return 0;
}
