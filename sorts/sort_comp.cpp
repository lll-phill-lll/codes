#include <stdio.h>
#include <vector>
#include <iterator>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using std::vector;

// insert
void insert(vector<int>::iterator vec_beg, vector<int>::iterator vec_end) {
    for (auto it = vec_beg; it != vec_end; ++it) {
        int t = *it;
        auto jt = it;
        while (jt > vec_beg && *(jt - 1) > t) {
            *(jt) = *(jt - 1);
            --jt;
        }
        *(jt) = t;
    }
}

// bubble
void bubble(vector<int>::iterator vec_beg, vector<int>::iterator vec_end) {
    for (auto i = vec_beg; i != vec_end; ++i) {
        for (auto j = vec_beg; j != vec_end; ++j) {
            if (*i < *j) {
                std::swap(*i, *j);            }
        }
    }
}


// qsort
vector<int>::iterator partition(vector<int>::iterator vec_beg,
                                vector<int>::iterator vec_end, int op) {
    auto left = vec_beg;
    auto right = vec_end - 1;
    while (left < right) {
        while (*left < op) ++left;
        while (*right > op) --right;
        if (*right == *left) {
            ++left;
        } else if (left < right) {
            std::swap(*left, *right);
        }
    }
    return right;
}
void qsort(vector<int>::iterator vec_beg, vector<int>::iterator vec_end) {
    int op = vec_beg[(vec_end - vec_beg) / 2 - (vec_end - vec_beg) / 4 + (vec_end - vec_beg) / 8];
    if (vec_end > vec_beg + 1) {
        vector<int>::iterator p = partition(vec_beg, vec_end, op);
        qsort(vec_beg, p);
        qsort(p + 1, vec_end);
    } else {
        return;
    }
}

// merge sort
vector<int> compare(vector<int>::iterator v_beg, vector<int>::iterator v_mid, vector<int>::iterator v_end) {
    auto v1_beg = v_beg, v1_end = v_mid, v2_beg = v_mid, v2_end = v_end;
    vector<int> res(v1_end - v1_beg + v2_end - v2_beg);
    int i = 0;
    while (v1_end - v1_beg && v2_end - v2_beg) {
        if (*v1_beg >= *v2_beg) {
            res[i] = *v2_beg;
            ++v2_beg;
        } else {
            res[i] = *v1_beg;
            ++v1_beg;
        }
        ++i;
    }
    if (v1_beg != v1_end) {
        while (v1_beg != v1_end) {
            res[i] = *v1_beg;
            ++v1_beg;
            ++i;
        }
    }
    if (v2_beg != v2_end) {
        while (v2_beg != v2_end) {
            res[i] = *v2_beg;
            ++v2_beg;
            ++i;
        }
    }
    return res;
}

void my_merge(vector<int>::iterator vec_beg, vector<int>::iterator vec_end) {
    int size_ = vec_end - vec_beg;
    if (size_ < 2) return;
    int t = (vec_end - vec_beg) / 2;
    vector<int>::iterator m = vec_beg + t;
    my_merge(vec_beg, m);
    my_merge(m, vec_end);
    vector<int> v = compare(vec_beg, m, vec_end);
    std::copy(v.begin(), v.end(), vec_beg);
}

//quick + bubble
void quick_bubble(vector<int>::iterator vec_beg, vector<int>::iterator vec_end) {
    if (vec_end - vec_beg > 100) {
        qsort(vec_beg, vec_end);
    } else {
        bubble(vec_beg, vec_end);
    }
}

//quick + inserts
void quick_insert(vector<int>::iterator vec_beg, vector<int>::iterator vec_end) {
    if (vec_end - vec_beg > 100) {
        qsort(vec_beg, vec_end);
    } else {
        insert(vec_beg, vec_end);
    }
}

// heap
void heapify(vector<int>::iterator vec_beg, vector<int>::iterator vec_end, vector<int>::iterator pos) {
    auto maxi = pos;
    auto left = pos + (pos - vec_beg);
    auto right = pos + (pos - vec_beg) + 1;
    if (left < vec_end && *left > *maxi) {
        maxi = left;
    }
    if (right < vec_end && *right > *maxi) {
        maxi = right;
    }
    if (maxi != pos) {
        std::swap(*maxi, *pos);
        heapify(vec_beg, vec_end, maxi);
    }
}

void heap(vector<int>::iterator vec_beg, vector<int>::iterator vec_end) {
    for (auto it = vec_end - (vec_end - vec_beg) / 2 - 1; it >= vec_beg; --it) {
        heapify(vec_beg, vec_end, it);
    }
    for (auto it = vec_end - 1; it >= vec_beg; --it) {
        std::swap(*vec_beg, *it);
        heapify(vec_beg, it, vec_beg);
    }
}

int main() {
    std::srand(time(0));
    std::cout << "Enter array size:" << std::endl;
    int len;
    std::cin >> len;
    std::cout << "Do you want to switch on bubble and inserts sorts?" << std::endl << "It requires more time with large arrays." << std::endl;
    std::cout << "Enter 1 or 0" << std::endl;
    bool sw;
    std::cin >> sw;
    std::vector<int> numbers_qsort(len);
    std::vector<int> numbers_heap(len);
    std::vector<int> numbers_heap_std(len);
    std::vector<int> numbers_qsort_and_bubble(len);
    std::vector<int> numbers_qsort_and_insert(len);
    std::vector<int> numbers_merge(len);
    std::vector<int> numbers_insert(len);
    std::vector<int> numbers_bubble(len);
    std::vector<int> numbers_qsort_std(len);

    for (int i = 0; i != len; ++i) {
        int t = (std::rand() - std::rand()) * (std::rand() / 1000);
        numbers_qsort[i] = t;
        numbers_heap[i] = t;
        numbers_heap_std[i] = t;
        numbers_merge[i] = t;
        if (sw) {
            numbers_insert[i] = t;
            numbers_bubble[i] = t;
        }
        numbers_qsort_std[i] = t;
        numbers_qsort_and_bubble[i] = t;
        numbers_qsort_and_insert[i] = t;
    }
    // qsort
    unsigned int start_time_qsort = clock();
    qsort(numbers_qsort.begin(), numbers_qsort.end());
    unsigned int end_time_qsort = clock();
    int time_qsort = end_time_qsort - start_time_qsort;
    std::cout << "Quick sort:" << "\t" << time_qsort / 1000 << "s " << time_qsort % 1000 << "ms" << std::endl;

    // merge
    unsigned int start_time_merge = clock();
    qsort(numbers_merge.begin(), numbers_merge.end());
    unsigned int end_time_merge = clock();
    int time_merge = end_time_merge - start_time_merge;
    std::cout << "Merge sort:" << "\t" << time_merge / 1000 << "s " << time_merge % 1000 << "ms" << std::endl;

    // qsort_std
    unsigned int start_time_qsort_std = clock();
    std::sort(numbers_qsort_std.begin(), numbers_qsort_std.end());
    unsigned int end_time_qsort_std = clock();
    int time_qsort_std = end_time_qsort_std - start_time_qsort_std;
    std::cout << "Std quick sort:" << "\t" << time_qsort_std / 1000 << "s " << time_qsort_std % 1000 << "ms" << std::endl;

    // heap
    unsigned int start_time_heap = clock();
    heap(numbers_heap.begin(), numbers_heap.end());
    unsigned int end_time_heap = clock();
    int time_heap = end_time_heap - start_time_heap;
    std::cout << "Heap sort:" << "\t" << time_heap / 1000 << "s " << time_heap % 1000 << "ms" << std::endl;

    // heap_std
    unsigned int start_time_heap_std = clock();
    std::make_heap(numbers_heap_std.begin(), numbers_heap_std.end());
    std::sort_heap(numbers_heap_std.begin(), numbers_heap_std.end());
    unsigned int end_time_heap_std = clock();
    int time_heap_std = end_time_heap_std - start_time_heap_std;
    std::cout << "Std heap sort:" << "\t" << (time_heap_std) / 1000 << "s " << time_heap_std % 1000 << "ms" << std::endl;

    if (sw) {
        // bubble
        unsigned int start_time_bubble = clock();
        bubble(numbers_bubble.begin(), numbers_bubble.end());
        unsigned int end_time_bubble = clock();
        int time_bubble = end_time_bubble - start_time_bubble;
        std::cout << "Bubble sort:" << "\t" << time_bubble / 1000 << "s " << time_bubble % 1000 << "ms" << std::endl;

        // insert
        unsigned int start_time_insert = clock();
        insert(numbers_insert.begin(), numbers_insert.end());
        unsigned int end_time_insert = clock();
        int time_insert = end_time_insert - start_time_insert;
        std::cout << "Inserts sort:" << "\t" << time_insert / 1000 << "s " << time_insert % 1000 << "ms" << std::endl;
    }

    // qsort + bubble
    unsigned int start_time_qsort_and_bubble = clock();
    quick_bubble(numbers_qsort_and_bubble.begin(), numbers_qsort_and_bubble.end());
    unsigned int end_time_qsort_and_bubble = clock();
    int time_qsort_and_bubble = end_time_qsort_and_bubble - start_time_qsort_and_bubble;
    std::cout << "Quick sort + bubble sort:" << "\t" << time_qsort_and_bubble / 1000 << "s " << time_qsort_and_bubble % 1000 << "ms" << std::endl;

    // qsort + inserts
    unsigned int start_time_qsort_and_insert = clock();
    quick_insert(numbers_qsort_and_insert.begin(), numbers_qsort_and_insert.end());
    unsigned int end_time_qsort_and_insert = clock();
    int time_qsort_and_insert = end_time_qsort_and_insert - start_time_qsort_and_insert;
    std::cout << "Quick sort + inserts sort:" << "\t" << time_qsort_and_insert / 1000 << "s " << time_qsort_and_insert % 1000 << "ms" << std::endl;

    std::cout << "To check if the algorithms work correctly using if_sorted function, enter 1," << std::endl << "otherwise enter 0:" << std::endl;
    int y;
    std::cin >> y;
    if (y) {
        if (std::is_sorted(numbers_qsort.begin(), numbers_qsort.end())) {
            std::cout << "Quick sort works correctly." << std::endl;
        } else {
            std::cout << "Quick sort works wrong." << std::endl;
        }
        if (std::is_sorted(numbers_merge.begin(), numbers_merge.end())) {
            std::cout << "Merge sort works correctly." << std::endl;
        } else {
            std::cout << "Merge sort works wrong." << std::endl;
        }
        if (sw) {
            if (std::is_sorted(numbers_bubble.begin(), numbers_bubble.end())) {
                std::cout << "Bubble sort works correctly." << std::endl;
            } else {
                std::cout << "Bubble sort works wrong." << std::endl;
            }
            if (std::is_sorted(numbers_insert.begin(), numbers_insert.end())) {
                std::cout << "Inserts sort works correctly." << std::endl;
            } else {
                std::cout << "Inserts sort works wrong." << std::endl;
            }
        }
        if (std::is_sorted(numbers_qsort_and_bubble.begin(), numbers_qsort_and_bubble.end())) {
            std::cout << "Quick sort and bubble sort works correctly." << std::endl;
        } else {
            std::cout << "Quick sort and bubble sort works wrong." << std::endl;
        }
        if (std::is_sorted(numbers_qsort_and_insert.begin(), numbers_qsort_and_insert.end())) {
            std::cout << "Quick sort and inserts sort works correctly." << std::endl;
        } else {
            std::cout << "Quick sort and inserts sort works wrong." << std::endl;
        }
        if (std::is_sorted(numbers_heap.begin(), numbers_heap.end())) {
            std::cout << "Heap sort works correctly." << std::endl;
        } else {
            std::cout << "Heap sort works wrong." << std::endl;
        }
    }
}
