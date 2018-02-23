#include <iostream>
#include <string>
#include <vector>
#include <math.h>
int main() {
    setlocale( LC_ALL,"Russian");
    std::string s1, s2;
    std::cout << "Enter the first word:" << std::endl;
    std::cin >> s1;
    std::cout << "Enter the second word:" << std::endl;
    std::cin >> s2;
    std::cout << "Print all table 1/0?:" << std::endl;
    int t;
    std::cin >> t;
    int l1 = s1.length() + 1;
    int l2 = s2.length() + 1;
    // std::cout << l1 << " " << l2 << "\n";
    std::vector<std::vector<int>> table(l1 + 1, std::vector<int>(l2 + 1));
    for (int i = 0; i != l1; ++i) table[i][0] = i;
    for (int i = 0; i != l2; ++i) table[0][i] = i;
        /*for (int i = 0; i != l1; ++i) {
        for (int j = 0; j != l2; ++j) {
            std::cout << table[i][j] << "\t";
        }
        std::cout << std::endl;
        }*/
    for (int i = 1; i != l1; ++i) {
        for (int j = 1; j != l2; ++j) {
            int ind;
            if (s1[i - 1] != s2[j - 1]) {
                ind = 1;
            } else {
                ind = 0;
            }
            table[i][j] = std::min(table[i][j - 1] + 1, std::min(table[i - 1][j] + 1, table[i - 1][j - 1] + ind));
        }
    }
    if (t) {
        std::cout << "\t";
        for (int i = 0; i != s2.length(); ++i) std::cout << "\t" << s2[i];
        std::cout << std::endl;
        for (int i = 0; i != l1; ++i) {
            if (i != 0) {
                std::cout << s1[i - 1] << "\t";
            } else {
                std::cout << "\t";
            }
            for (int j = 0; j != l2; ++j) {
                std::cout << table[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    }

    std::cout << "Levenstein distance is  " << table[l1 - 1][l2 - 1] << std::endl;

    return 0;
}
