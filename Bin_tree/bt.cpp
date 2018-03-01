#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
bool is_balanced = true;
class node {
 private:
     int value;
     node * left;
     node * right;
     int times;

 public:
     // constructors:
     node() {
         value = 0;
         left = nullptr;
         right = nullptr;
     }
     explicit node(int val) {
         value = val;
         left = nullptr;
         right = nullptr;
         times = 1;
     }
     // destructor:
     ~node() {
         delete left;
         delete right;
     }
     // add nodes:
     void add_new_node(int val) {
         if (val > value) {
             add_left_node(val);
         } else if (val < value) {
             add_right_node(val);
         } else if (val == value) {
             ++times;
         }
     }
     void add_left_node(int val) {
         if (left == nullptr) {
             left = new node(val);
         } else {
             left -> add_new_node(val);
         }
     }
     void add_right_node(int val) {
         if (right == nullptr) {
             right = new node(val);
         } else {
             right -> add_new_node(val);
         }
     }
     void leafs() {
        if (right != nullptr) right->leafs();
        if (left == nullptr && right == nullptr) std::cout << value << std::endl;
        if (left != nullptr) left->leafs();
     }
     void cross() {
        if (right != nullptr) right->cross();
        if (left != nullptr && right != nullptr) std::cout << value << std::endl;
        if (left != nullptr) left->cross();
     }
     void branch() {
        if (right != nullptr) right->branch();
        if (left == nullptr && right != nullptr ||
            left != nullptr && right == nullptr) std::cout << value << std::endl;
        if (left != nullptr) left->branch();
     }
     int AVL() {
        if ((left == nullptr && right == nullptr)) return 1;
        int l_depth, r_depth;
        if (left != nullptr) {
            l_depth = left -> AVL() + 1;
        } else {
            l_depth = 1;
        }
        if (right != nullptr) {
            r_depth = right -> AVL() + 1;
        } else {
            r_depth = 1;
        }
        if (abs(l_depth - r_depth) > 1) is_balanced = false;
        if (l_depth >= r_depth) return l_depth;
        if (l_depth < r_depth) return r_depth;
        return -1;
     }
     // show:
     void print_sorted() {
            if (right != nullptr) right->print_sorted();
            std::cout << value << " " << times << std::endl;
            if (left != nullptr) left->print_sorted();
        }
     int m_depth() {
        // if (value == NULL && left == nullptr && right == nullptr) return 0;
        if ((left == nullptr && right == nullptr)) return 1;
        int l_depth, r_depth;
        if (left != nullptr) {
            l_depth = left -> m_depth() + 1;
        } else {
            l_depth = 1;
        }
        if (right != nullptr) {
            r_depth = right -> m_depth() + 1;
        } else {
            r_depth = 1;
        }
        if (l_depth >= r_depth) return l_depth;
        if (l_depth < r_depth) return r_depth;
        return -1;
     }
};

class bin_tree {
 private:
    node * root;

 public:
    bin_tree() {
        root = nullptr;
    }
    ~bin_tree() {
        delete root;
    }
    void add_node(int val) {
        if (root == nullptr) {
            root = new node(val);
        } else {
            root -> add_new_node(val);
        }
    }
    int max_tree_depth() {
        return root -> m_depth();
    }

    void print_sorted() const {
        if (root != nullptr) root -> print_sorted();
        }
    void leafs() {
        if (root != nullptr) root -> leafs();
    }
    void cross() {
        if (root != nullptr) root -> cross();
    }
    void branch() {
        if (root != nullptr) root -> branch();
    }
    int AVL() {
        if (root -> m_depth() <= 1) return 1;
        if (root != nullptr) return root -> AVL();
        return 0;
    }
};

int main() {
    bin_tree tree;
    int k = 0;
    std::cin >> k;
    while (k != 0) {
        tree.add_node(k);
        std::cin >> k;
    }
    tree.print_sorted();
    std::cout << std::endl;
    tree.leafs();
    std::cout << std::endl;
    tree.cross();
    std::cout << std::endl;
    tree.branch();
    std::cout << std::endl;
    std::cout << tree.max_tree_depth();
    std::cout << std::endl;
    if (is_balanced) std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;
    return 0;
}

