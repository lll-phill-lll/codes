#include <iostream>
#include <vector>
#include <algorithm>

struct nodes {
    int weight;
    int first;
    int second;
    bool operator < (nodes b) {
        return weight < b.weight;
    }
};

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> tree_num(n + 1);
    for (int i = 1; i != n + 1; ++i) {
        tree_num[i] = i;
    }
    std::vector<nodes> res(m);
    nodes node;
    for (int i = 0; i != m; ++i) {
        std::cin >> node.first >> node.second >> node.weight;
        res[i] = node;
    }
    int w = 0;
    std::sort(res.begin(), res.end());
    int first, second, weight;
    for (nodes trees : res) {
        first = trees.first;
        second = trees.second;
        weight = trees.weight;
        if (tree_num[first] != tree_num[second]) {
            w += weight;
            int old = tree_num[second];
            for (int i = 1; i != n + 1; ++i) {
                if (tree_num[i] == old) {
                    tree_num[i] = tree_num[first];
                }
            }
        }
    }
    std::cout << w << std::endl;
    return 0;
}

