#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <utility>


class SuffixArray {
private:
    std::string text;
    std::string alphabet;
    std::unordered_map<char, int> alphabet_to_num;
    std::vector<int> SortCharacters();
    std::vector<int> ComputeCharClasses(std::vector<int>);
    std::vector<int> SortDoubles(int l, std::vector<int>, std::vector<int>);
    std::vector<int> UpdateClasses(std::vector<int>, std::vector<int>, int);
public:
    std::vector<int> Build();
    std::pair<int, int> MatchPattern(std::vector<int>, std::string);
    SuffixArray(std::string t, std::string alph) {
        text = t;
        alphabet = alph;
        std::sort(alphabet.begin(), alphabet.end());
        for (int i = 0; i != alph.length(); ++i) {
            alphabet_to_num[alphabet[i]] = i;
        }
    }

};

std::vector<int> SuffixArray::SortCharacters() {
    int len = text.length();
    std::vector<int> order(len, 0);
    std::vector<int> count(alphabet.length(), 0);

    for (int i = 0; i != len; ++i) {
        ++count[alphabet_to_num[text[i]]];
    }

    for(int i = 1; i != alphabet.length(); ++i) {
        count[i] += count[i - 1];
    }
    for (int i = len - 1; i != 0; --i) {
        char c = text[i];
        int ind = alphabet_to_num[text[i]];
        --count[ind];
        order[count[ind]] = i;
    }
    return order;
}


std::vector<int> SuffixArray::ComputeCharClasses(std::vector<int> order) {
    std::vector<int> char_class(text.length());
    char_class[order[0]] = 0;
    for (int i = 1; i != text.length(); ++i) {
        if (text[order[i]] != text[order[i - 1]]) {
            char_class[order[i]] = char_class[order[i - 1]] + 1;
        } else {
            char_class[order[i]] = char_class[order[i - 1]];
        }
    }
    return char_class;
}



std::vector<int> SuffixArray::SortDoubles(int l, std::vector<int> order, std::vector<int> char_class) {
   std::vector<int> count(text.length(), 0);
   std::vector<int> new_order(text.length());
   for (int i = 0; i != text.length(); ++i) {
       ++count[char_class[i]];
   }
   for (int i = 1; i != text.length(); ++i) {
       count[i] += count[i - 1];
   }
   for (int i = text.length() - 1; i >= 0; --i) {
       int start = abs(order[i] - l + text.length()) % text.length();
       int cl = char_class[start];
       --count[cl];
       new_order[count[cl]] = start;
   }
   return new_order;
}

std::vector<int> SuffixArray::UpdateClasses(std::vector<int> new_order, std::vector<int> char_class, int l) {
    int n = new_order.size();
    std::vector<int> new_char_class(n);
    new_char_class[new_order[0]] = 0;
    for (int i = 1; i != n; ++i) {
        int cur = new_order[i];
        int prev = new_order[i - 1];
        int mid = cur + l;
        int mid_prev = abs(prev + l) % n;
        if (char_class[cur] != char_class[prev] || char_class[mid] != char_class[mid_prev]) {
            new_char_class[cur] = new_char_class[prev] + 1;
        } else {
            new_char_class[cur] = new_char_class[prev];
        }
    }
    return new_char_class;
}


std::vector<int> SuffixArray::Build() {
   std::vector<int> order = SortCharacters();
   std::vector<int> char_class = ComputeCharClasses(order);
   int l = 1;
   while (l < text.length()) {
       order = SortDoubles(l, order, char_class);
       char_class = UpdateClasses(order, char_class, l);
       l *= 2;
   }
   return order;
}



std::pair<int, int> SuffixArray::MatchPattern(std::vector<int> suffix_array, std::string pattern) {
    int min_index = 0;
    int max_index = text.length();
    int mid_index;
    while (min_index < max_index) {
        mid_index = (min_index + max_index) / 2;
        std::string sub = text.substr(suffix_array[mid_index], pattern.length() - 1);
        if (sub[sub.length() - 1] != '$') {
            sub += "$";
        }
        if (pattern > sub) {
            // std::cout << pattern << " > " << sub << std::endl;
            min_index = mid_index + 1;
        } else {
            // std::cout << pattern << " <= " << sub << std::endl;
            max_index = mid_index;
        }
    }
    int start = min_index;
    max_index = text.length();
    while (min_index < max_index) {
        mid_index = (min_index + max_index) / 2;
        std::string sub = text.substr(suffix_array[mid_index], pattern.length() - 1);
        if (sub[sub.length() - 1] != '$') {
            sub += "$";
        }
        if (pattern < sub) {
            // std::cout << pattern << " < " << sub << std::endl;
            max_index = mid_index;
        } else {
            // std::cout << pattern << " >= " << sub << std::endl;
            min_index = mid_index + 1;
        }
    }
    int fin = max_index;
    if (start > fin) {
        return std::make_pair(-1, -1);
    } else {
        return std::make_pair(start, fin);
    }
}




int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string text;
    std::cin >> text;
    text += "$";
    /*std::unordered_set<char> all_chars;
    for (auto ch : text) {
        all_chars.insert(ch);
    }*/
    std::string alph = "GATC$";
    /*for (auto ch : all_chars) {
       alph += ch;
    }*/
    SuffixArray arr(text, alph);
    std::vector<int> a = arr.Build();

    int n;
    std::cin >> n;
    std::set<int> ans;
    for (int u = 0; u != n; ++u) {
        std::string look_for;
        std::cin >> look_for;
        look_for += "$";
        std::pair<int, int> res = arr.MatchPattern(a, look_for);
        // std::cout << res.first << " " << res.second << std::endl;
        /*for (auto i : a) {
            std::cout << i << " ";
        }
        std::cout << std::endl;*/
        if (res.first != -1) {
            for (int i = res.first; i != res.second; ++i) {
                ans.insert(a[i]);
            }
        }
    }
    for (auto k : ans) {
        std::cout << k << " ";
    }
    return 0;
}
