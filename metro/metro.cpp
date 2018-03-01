#include <deque>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>
#include <utility>

int main() {
    int num;
    std::cin >> num;
    int l;
    std::cin >> l;
    std::vector<std::unordered_set<int>> lines(l + 1);
    // std::vector<std::unordered_set<int>> nodes(num + 1);
    int p;
    int u;
    for (int i = 1; i != l + 1; ++i) {
        std::cin >> p;
        for (int j = 0; j != p; ++j) {
            std::cin >> u;
            lines[i].insert(u);
            // nodes[u].insert(i);
        }
    }
    int beg, fin;
    int len = 0;
    std::unordered_set<int> nodes;
    std::unordered_set<int> nodes_res;
    std::vector<std::unordered_set<int>> nodes_with_lens(l - 1);
    std::vector<int> lines_with_lens(l + 1);
    std::cin >> beg >> fin;
    nodes.insert(beg);
    bool found_res = false;
    for (int i = 0; i != l; ++i) {
        len = i;
        // nodes = nodes_res;
        // bool found_res = false;
        for (int j = 1; j != l + 1; ++j) {
            bool found = false;
            for (auto it : lines[j]) {
                if (nodes.find(it) != nodes.end()) {
                    found = true;
                    break;
                }
            }
            if (found) {
                for (auto it : lines[j]) {
                    nodes_res.insert(it);
                }
            }
            if (nodes_res.find(fin) != nodes_res.end()) {
                std::cout << i;
                found_res = true;
                break;
            }
        }
        nodes = nodes_res;
        if (found_res) break;
    }
    if (!found_res) std::cout << -1;
}

