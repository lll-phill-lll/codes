#include <iostream>
#include <set>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <algorithm>

void makeMedianSet(double& num, std::set<double>& approxSet, int &maxSetSize, int &moreThenMaximum, int &lessThenMinimum) {
    if (approxSet.size() <= maxSetSize) {
            approxSet.insert(num);
        } else if (lessThenMinimum < moreThenMaximum) {
            if (num <= *(approxSet.begin())) {
                ++lessThenMinimum;
            } else {
                approxSet.insert(num);
                if (approxSet.size() > maxSetSize) {
                    approxSet.erase(approxSet.begin());
                    ++lessThenMinimum;
                }
            }
        } else if (lessThenMinimum > moreThenMaximum) {
            if (num >= *(approxSet.rbegin())) {
                ++moreThenMaximum;
            } else {
                approxSet.insert(num);
                if (approxSet.size() > maxSetSize) {
                    approxSet.erase(*(approxSet.rbegin()));
                    ++moreThenMaximum;
                }
            }
        } else if (lessThenMinimum == moreThenMaximum) {
            bool left = rand() % 2;
            approxSet.insert(num);
                if (approxSet.size() > maxSetSize) {
                    if (!left) {
                        approxSet.erase(*(approxSet.rbegin()));
                        ++moreThenMaximum;
                    } else {
                        approxSet.erase(*(approxSet.begin()));
                        ++lessThenMinimum;
                    }
                }
        }
}

double findMedian(std::set<double> & approxSet, int & lessThenMinimum, int & moreThenMaximum) {
    int medianPos = (approxSet.size() / 2);
    int dif;
    if (lessThenMinimum < moreThenMaximum) {
        dif = moreThenMaximum - lessThenMinimum;
        if (dif > approxSet.size() / 2) {
            return *(approxSet.rbegin());
        } else {
            medianPos += dif / 2;
        }
     } else if (lessThenMinimum > moreThenMaximum) {
        dif = lessThenMinimum - moreThenMaximum;
        if (dif > approxSet.size() / 2) {
            return *(approxSet.rend());
        } else {
            medianPos -= dif / 2;
        }
     }
    size_t pos = 0;
    for (auto it = approxSet.begin(); it != approxSet.end(); ++it) {
        if (pos == medianPos) return *it;
        ++pos;
    }
}

void makeStreamUsual(std::vector<double> &stream, int & n) { // fill the stream with random numbers 
    for (int i = 0; i != n; ++i) {
        stream.push_back(rand() % 10000);
    }
}

void makeStreamLognormalDistribution(std::vector<double> & stream, int & n) { // fill the stream with lognormal distributed numbers
    std::random_device rd;
    std::mt19937 gen(rd());

    std::lognormal_distribution<> d(1.6, 0.25);

    for(int i = 0; i != n; ++i) {
        stream.push_back(d(gen));
    }
}

double checkTheChoise(std::vector<double> & stream, double & median) { // check how many numbers under and above found median in the stream
    double left = 0, right = 0;
    for (int i : stream) {
        if (i >= median) {
            ++right;
        } else {
            ++left;
        }
    }
    return std::min(left, right) / std::max(left, right);
}

int main() {
    srand (time(NULL));
    std::cout << "Imitating the stream with random distribution, insert the size of stream: \n";
    int n;
    std::cin >> n;
    std::vector<double> stream; // our stream
    makeStreamUsual(stream, n);
    std::set<double> approxSet; // set with approximated version of stream
    int lessThenMinimum = 0, moreThenMaximum = 0; 
    int maxSetSize = 100;

    // imitate the stream
    for (auto num : stream) {
        makeMedianSet(num, approxSet, maxSetSize, moreThenMaximum, lessThenMinimum);
    }
    // find mediana in set depending on the numder of elements which less then minimum in approx set and larger them maximum
    double median = findMedian(approxSet, lessThenMinimum, moreThenMaximum);
    std::cout << "Found median is: \n";
    std::cout << median << std::endl;
    std::sort(stream.begin(), stream.end());
    std::cout << "Real median is: \n";
    std::cout << stream[(stream.size() / 2)] << std::endl;
    // accuracy: number if elements less median divided by number of lements larger median
    // The closer the result to 1 then the higher the accuracy
    std::cout << "Accuracy: \n";
    std::cout << checkTheChoise(stream, median) << std::endl;
    // the same but for lognormal distribution
    std::cout << "Imitating the stream with lognormal distribution, insert the size of stream: \n";
    std::cin >> n;
    stream.clear();
    approxSet.clear();
    makeStreamLognormalDistribution(stream, n);
    lessThenMinimum = 0;
    moreThenMaximum = 0;
    for (auto num : stream) {
        makeMedianSet(num, approxSet, maxSetSize, moreThenMaximum, lessThenMinimum);
    }
    median = findMedian(approxSet, lessThenMinimum, moreThenMaximum);
    std::cout << "Found median is: \n";
    std::cout << median << std::endl;
    std::sort(stream.begin(), stream.end());
    std::cout << "Real median is: \n";
    std::cout << stream[(stream.size() / 2)] << std::endl;
    std::cout << "Accuracy: \n";
    std::cout << checkTheChoise(stream, median) << std::endl;


    return 0;
}
