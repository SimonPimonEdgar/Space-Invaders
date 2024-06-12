#include <iostream>
#include <ctime>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>

int main() {
    int NUM = 1000000;
    int NUM2 = 10000;

    // Time resize for std::vector
    std::clock_t start = std::clock();
    std::vector<int> vec;
    vec.resize(NUM);
    std::clock_t dt = std::clock() - start;
    std::cout << "Time for resize() on std::vector: " << float(dt) / CLOCKS_PER_SEC << " sec\n";

    // Time resize for std::deque
    start = std::clock();
    std::deque<int> deq;
    deq.resize(NUM);
    dt = std::clock() - start;
    std::cout << "Time for resize() on std::deque: " << float(dt) / CLOCKS_PER_SEC << " sec\n";

    // Time std::list
    start = std::clock();
    std::list<int> lst;
    for (int i = 1; i < NUM; ++i) {
        lst.resize(i);
    }
    dt = std::clock() - start;
    std::cout << "Time for resize() on std::list: " << float(dt) / CLOCKS_PER_SEC << " sec\n";


    // Time push_back for std::vector
    start = std::clock();
    std::vector<int> vec2;
    for (int i = 0; i < NUM; ++i) {
        vec2.push_back(i);
    }
    dt = std::clock() - start;
    std::cout << "Time for push_back() on std::vector: " << float(dt) / CLOCKS_PER_SEC << " sec\n";

    // Time push_back for std::deque
    start = std::clock();
    std::deque<int> deq2;
    for (int i = 0; i < NUM; ++i) {
        deq2.push_back(i);
    }
    dt = std::clock() - start;
    std::cout << "Time for push_back() on std::deque: " << float(dt) / CLOCKS_PER_SEC << " sec\n";

    // Time push_back for std::list
    start = std::clock();
    std::list<int> lst2;
    for (int i = 0; i < NUM; ++i) {
        lst2.push_back(i);
    }
    dt = std::clock() - start;
    std::cout << "Time for push_back() on std::list: " << float(dt) / CLOCKS_PER_SEC << " sec\n";
}
