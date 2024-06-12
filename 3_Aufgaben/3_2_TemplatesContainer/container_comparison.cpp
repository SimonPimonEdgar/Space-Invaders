#include <iostream>
#include <ctime>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>

int main() {
    int NUM = 10000000;
    std::clock_t start = std::clock();

    start = std::clock(); 
    for(int i = 0; i<NUM; ++i) {
        // TODO Entsprechende Funktion auf Container testen
    };
    dt = std::clock() - start;
    std::cout << "TODO Time für TODO " << float(dt)/CLOCKS_PER_SEC << " sec\n"; 
}