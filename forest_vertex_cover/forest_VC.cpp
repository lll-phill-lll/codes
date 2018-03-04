#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>

void read_the_graph(std::vector<std::unordered_set<int>>& graph_list,
int n, std::set<std::pair<int, int>> &edges) {
    int adj;
    int vertex;
    for (int i = 0; i != n; ++i) {
        std::cin >> adj;
        for (int j = 0; j != adj; ++j) {
            std::cin >> vertex;
            graph_list[i].insert(vertex);
            edges.insert(std::make_pair(i, vertex));
            edges.erase(std::make_pair(vertex, i));
        }
    }
}

std::unordered_set<int> vertex_in_VC;

bool check_for_leafs(std::vector<std::unordered_set<int>> &graph_list,
std::set<std::pair<int, int>> &edges) {
    int number_of_zero_vert = 0;
    for (int i = 0; i != graph_list.size(); ++i) {
        if (graph_list[i].size() == 1) {
            int current_elem = *(graph_list[i].begin());
            vertex_in_VC.insert(current_elem);
            for (int neighb : graph_list[current_elem]) {
                edges.erase(std::make_pair(current_elem, neighb));
                edges.erase(std::make_pair(neighb, current_elem));
            }
            for (auto with : graph_list[current_elem]) {
                graph_list[with].erase(current_elem);
            }

            graph_list[current_elem].clear();
            graph_list[i].clear();
        } else {
            ++number_of_zero_vert;
        }
    }
    if (edges.size() == 0) return false;
    if (number_of_zero_vert == graph_list.size()) {
        return false;
    } else {
        return true;
    }
}

void find_VC(std::vector<std::unordered_set<int>> &graph_list,
std::set<std::pair<int, int>> &edges) {
    while (check_for_leafs(graph_list, edges)) {}
}




int main() {
    int n;
    std::cin >> n;
    std::vector<std::unordered_set<int>> graph_list(n);
    std::set<std::pair<int, int>> edges;
    read_the_graph(graph_list, n, edges);
    find_VC(graph_list, edges);
    std::cout << vertex_in_VC.size();
    return 0;
}

