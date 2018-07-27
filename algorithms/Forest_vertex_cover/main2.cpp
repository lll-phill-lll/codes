#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stdlib.h>
#include <time.h>


double distance(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

struct nodes {
    double weight;
    int first;
    int second;
    bool operator < (nodes b) {
        return weight < b.weight;
    }
};

double min_weight(std::vector<nodes>  res, int n) {
    std::vector<int> tree_num(n + 1);
    for (int i = 1; i != n + 1; ++i) {
        tree_num[i] = i;
    }
    double w = 0;
    std::sort(res.begin(), res.end());
    int first, second;
    double weight;
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
    return w;
}

void count_weights(std::vector<std::pair<int, int>> & coord,
                   std::vector<nodes> & res, int n) {
    int x1, x2, y1, y2;
    double dist;
    nodes node;
    for (int i = 0; i != n - 1; ++i) {
        for (int j = i + 1; j != n; ++j) {
            x1 = coord[i].first;
            y1 = coord[i].second;
            x2 = coord[j].first;
            y2 = coord[j].second;
            dist = distance(x1, y1, x2, y2);
            node.first = i;
            node.second = j;
            node.weight = dist;
            res.push_back(node);
        }
    }
}

void count_weight_optimised(std::vector<std::pair<int, int>> & coord,
                            std::vector<nodes> & res, int n) {
    int x1, x2, y1, y2;
    double dist;
    nodes node;
    for (int i = n; i != coord.size() - 1; ++i) {
        for (int j = i + 1; j != coord.size(); ++j) {
            x1 = coord[i].first;
            y1 = coord[i].second;
            x2 = coord[j].first;
            y2 = coord[j].second;
            dist = distance(x1, y1, x2, y2);
            node.first = i;
            node.second = j;
            node.weight = dist;
            res.push_back(node);
        }
    }
}


int main() {
    srand(time(NULL));
    int n, k;
    std::cin >> n >> k;
    std::vector<std::pair<int, int>> coord(n);
    int x, y;
    int xmax = -1, ymax = -1;
    for (int i = 0; i != n; ++i) {
        std::cin >> x >> y;
        if (x > xmax) xmax = x;
        if (y > ymax) ymax = y;
        coord[i] = std::make_pair(x, y);
    }
    double minimum;
    std::vector<nodes> res;
    std::vector<nodes> cool_routers;
    count_weights(coord, res, n);
    minimum = min_weight(res, n);
    int village_num;
    int rand_x, rand_y;
    for (int y = 0; y != 20; ++y) {
        int p = rand() % k;
        for (int i = 0; i != p; ++i) {
            village_num = rand() % n;
            rand_x = rand() % xmax;
            rand_y = rand() % ymax;
            coord.push_back(std::make_pair(rand_x, rand_y));
        }
        res.clear();
        count_weights(coord, res, n);
        double local_minimum = min_weight(res, n + p);
        if (local_minimum < minimum) {
            minimum = local_minimum;
            cool_routers.clear();
            std::cout << '+';
            for (int u = 0; u != p; ++u) {
                cool_routers.push_back(*(res.end() - 1));
                res.pop_back();
                coord.pop_back();
            }
        } else {
            for (int u = 0; u != p; ++u) {
                res.pop_back();
                coord.pop_back();
            }
        }
    }
    std::cout << cool_routers.size() << std::endl;
    for (auto i : cool_routers) {
        std::cout << i.first << " " << i.second << std::endl;
    }
    return 0;
}
