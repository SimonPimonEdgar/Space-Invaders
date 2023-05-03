#include <iostream>
#include <ctime>

int main() {
    int NUM = 10000000;
    std::clock_t start = std::clock();
    for (int i = 0;i<NUM;++i){
        Point p[1000];
    }
    std::clock_t dt = std::clock() - start;    
    std::cout << "Stack Time " << float(dt)/CLOCKS_PER_SEC << " sec\n";

    start = std::clock(); 
    for(int i = 0; i<NUM; ++i) {
        Point *p = new Point[1000];
        delete[] p;
    };
    dt = std::clock() - start;
    std::cout << "Heap Time " << float(dt)/CLOCKS_PER_SEC << " sec\n"; 
}