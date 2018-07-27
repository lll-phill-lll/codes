#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <utility>
#include <set>
#include <ctime>


void read_the_graph(std::vector<std::unordered_set<int>>::iterator beg,
int m, std::set<std::pair<int, int>> &edges) {
    int l, r;
    for (size_t i = 0; i != m; ++i) {
        std::cin >> l >> r;
        (*(beg + l - 1)).insert(r - 1);
        (*(beg + r - 1)).insert(l - 1);
        edges.insert(std::make_pair(l - 1, r - 1));
    }
}

void print_the_graph(std::vector<std::unordered_set<int>>::iterator beg,
std::vector<std::unordered_set<int>>::iterator end) {
    for (auto it = beg; it != end; ++it) {
            std::cout << it - beg << ":";
        for (int nums : (*it)) {
            std::cout << nums << " ";
        }
    std::cout << std::endl;
    }
}


bool correct_vector_cover(std::vector<int> &vertex_in_VC, std::set<std::pair<int, int>> &edges) {
    for (auto i : edges) {
        if (vertex_in_VC[i.first] == 0 && vertex_in_VC[i.second] == 0) {
            return false;
        }
    }
    return true;
}

std::vector<int> answer;
std::vector<int> answer2;


int main() {
    int n, m, k;
    srand(time(0));
    std::cin >> n >> m >> k;
    std::vector<int> vertex_in_VC(n, 0);
    std::vector<std::unordered_set<int>> graph_list(n);
    std::set<std::pair<int, int>> edges;
    read_the_graph(graph_list.begin(), m, edges);
    std::vector<int> vertex_to_rand;
    // print_the_graph(graph_list.begin(), graph_list.end());
    for (int t = 0; t != n * 500; ++t) {
        vertex_to_rand.clear();
        int nodes_in_cover = k + rand() % (n - k + 1);
        for (int i = 0; i != n; ++i) {
            vertex_in_VC[i] = 0;
        }
        for (int i = 0; i != nodes_in_cover; ++i) {
            int current_node = rand() % n;
            vertex_in_VC[current_node] = 1;
            vertex_to_rand.push_back(current_node);
        }
        if (correct_vector_cover(vertex_in_VC, edges)) {
            int s = n * 15;
            for (int y = 0; y != s; ++y) {
                int to_delete = rand() % vertex_to_rand.size();
                vertex_in_VC[vertex_to_rand[to_delete]] = 0;
                if (correct_vector_cover(vertex_in_VC, edges) == false) {
                    vertex_in_VC[vertex_to_rand[to_delete]] = 1;
                } else {
                    vertex_to_rand.erase(vertex_to_rand.begin() + to_delete);
                    int sum = 0;
                    for (int nut : vertex_in_VC) {
                        if (nut == 1) ++sum;
                    }
                    if (sum == k) {
                        answer = vertex_in_VC;
                        break;
                    }
                }
            }
        }
        if (answer.size() != 0) {
            break;
        }
    }
    if (answer.size() == 0) {
        std::cout << "No";
    } else {
        std::cout << "Yes" << std::endl;
        for (int i = 0; i != answer.size(); ++i) {
            if (answer[i] == 1) {
                std:: cout << i + 1 << " ";
            }
        }
    }
    return 0;
}

