#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <utility>
#include <set>

std::unordered_set<int> answer;

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

void prework(std::vector<std::unordered_set<int>> &graph_list,
                        std::unordered_set<int> &vertex_in_VC,
                        std::unordered_set<int> &vertex_out_VC,
                        int k, int n,
                        std::set<std::pair<int, int>> &edges) {
    for (int i = 0; i != n; ++i) {
        int s = graph_list[i].size();
        if (s > k) {
            vertex_in_VC.insert(i);
            vertex_out_VC.erase(i);
        }
        if (s == 1) {
            int p = *graph_list[i].begin();
            // std::cout << i << " ";
            vertex_in_VC.insert(p);
            vertex_out_VC.erase(p);
            vertex_out_VC.erase(i);
        }
    }
}


void find_vertex_cover(std::vector<std::unordered_set<int>> &graph_list,
                        std::unordered_set<int> vertex_in_VC,
                        std::unordered_set<int> vertex_out_VC,
                        int k,
                        std::set<std::pair<int, int>> &edges) {
    if (vertex_in_VC.size() == k) {
        for (auto edge : edges) {
            if (vertex_in_VC.find(edge.first) == vertex_in_VC.end() &&
            vertex_in_VC.find(edge.second) == vertex_in_VC.end()) {
                return;
            }
        }
        answer = vertex_in_VC;
        return;
    } else if (vertex_in_VC.size() > k) {
        return;
    } else if (vertex_in_VC.size() < k) {
        int maxi_neighbours_index = -1;
        int maxi_neighbours = -1;
        for (int i : vertex_out_VC) {
            int s = graph_list[i].size();
            if (maxi_neighbours < s) {
                maxi_neighbours = graph_list[i].size();
                maxi_neighbours_index = i;
            }
        }
        int elem = maxi_neighbours_index;
        // std::cout << elem << " ";
        if (maxi_neighbours == 2) {
            vertex_in_VC.insert(elem);
            vertex_out_VC.erase(elem);
            find_vertex_cover(graph_list, vertex_in_VC, vertex_out_VC, k, edges);
        } else {
            vertex_in_VC.insert(elem);
            vertex_out_VC.erase(elem);
            find_vertex_cover(graph_list, vertex_in_VC, vertex_out_VC, k, edges);
            vertex_in_VC.erase(elem);
            for (int connected_vertex : graph_list[elem]) {
                vertex_in_VC.insert(connected_vertex);
                vertex_out_VC.erase(connected_vertex);
            }
            find_vertex_cover(graph_list, vertex_in_VC, vertex_out_VC, k, edges);
        }
        return;
    }
}




int main() {
    int n, m;
    std::cin >> n;
    std::unordered_set<int> vertex_in_VC;
    std::unordered_set<int> vertex_out_VC;
    for (int i = 0; i != n; ++i) {
        vertex_out_VC.insert(i);
    }
    std::vector<std::unordered_set<int>> graph_list(n);
    std::set<std::pair<int, int>> edges;
    read_the_graph(graph_list, n, edges);
    // print_the_graph(graph_list.begin(), graph_list.end());
    // prework(graph_list, vertex_in_VC, vertex_out_VC, k, n, edges);
    for (int k = n - 1; k > 0; --k) {
        for (int i = 0; i != n; ++i) {
            vertex_out_VC.insert(i);
        }
        vertex_in_VC.clear();
        find_vertex_cover(graph_list, vertex_in_VC, vertex_out_VC, k, edges);
    }
    std::cout << answer.size();
    return 0;
}
