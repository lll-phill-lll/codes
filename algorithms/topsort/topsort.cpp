#include <iostream>
#include <unordered_set>
#include <vector>
#include <deque>
#include <map>

void topsort(int v, std::map<int, std::unordered_set<int>> & table, std::deque<int> & q,
             std::unordered_set<int> & been, std::unordered_set<int> & check_acycle, bool & cycle) {
    been.insert(v);
    check_acycle.insert(v);
    for (auto it : table[v]) {
        if (check_acycle.find(it) != check_acycle.end()) {
            cycle = true;
        }
        if (been.find(it) == been.end()) {
            topsort(it, table, q, been, check_acycle, cycle);
        }
    }
    q.push_back(v);
}

int main() {
    size_t m;
    std::cout << "Enter number of edges:\n";
    std::cin >> m;
    std::map<int, std::unordered_set<int>> table;
    std::unordered_set<int> been;
    int a, b;
    std::unordered_set<int> all_nodes;
    std::cout << "Enter " << m << " edges:\n";
    for (size_t i = 0; i != m; ++i) {
        std::cin >> a >> b;
        all_nodes.insert(a);
        all_nodes.insert(b);
        table[a].insert(b);
    }
    bool cycle = false;
    std::unordered_set<int> check_acycle;
    std::deque<int> q;
    for (int i : all_nodes) {
        if (been.find(i) == been.end() && !cycle) {
            check_acycle.clear();
            topsort(i, table, q, been, check_acycle, cycle);
        }
    }
    int l;
    if (cycle) {
        std::cout << -1 << std::endl;
    } else {
        while (q.size()) {
            l = q.back();
            q.pop_back();
            std::cout << l << " ";
        }
    }
    return 0;
}
