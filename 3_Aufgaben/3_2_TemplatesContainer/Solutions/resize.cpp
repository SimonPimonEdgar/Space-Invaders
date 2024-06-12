#include <iostream>
#include <ctime>
#include <vector>
#include <deque>
#include <list>

int main() {
    int NUM = 10000000;

    // Time std::vector
    std::clock_t start = std::clock();
    std::vector<int> vec;
    for (int i = 1; i < NUM; ++i) {
        vec.resize(i);
    }
    std::clock_t dt = std::clock() - start;
    std::cout << "Time for std::vector: " << float(dt) / CLOCKS_PER_SEC << " sec\n";

    // Time std::deque
    start = std::clock();
    std::deque<int> deq;
    for (int i = 1; i < NUM; ++i) {
        deq.resize(i);
    }
    dt = std::clock() - start;
    std::cout << "Time for std::deque: " << float(dt) / CLOCKS_PER_SEC << " sec\n";

    // Time std::list
    start = std::clock();
    std::list<int> lst;
    for (int i = 1; i < NUM; ++i) {
        lst.resize(i);
    }
    dt = std::clock() - start;
    std::cout << "Time for std::list: " << float(dt) / CLOCKS_PER_SEC << " sec\n";

    return 0;
}