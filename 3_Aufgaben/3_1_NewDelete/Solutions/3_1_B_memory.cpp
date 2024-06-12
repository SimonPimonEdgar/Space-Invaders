#include <iostream>
#include <ctime>

struct Point { 
    float x, y;
}; 

int main() {
    int NUM = 10000000;
    std::clock_t start = std::clock();
    for (int i = 0;i<NUM;++i){
        Point p;
    }
    std::clock_t dt = std::clock() - start;    
    std::cout << "Stack Time " << float(dt)/CLOCKS_PER_SEC << " sec\n";

    start = std::clock(); 
    for(int i = 0; i<NUM; ++i) {
        Point *p = new Point;
        delete p;
    };
    dt = std::clock() - start;
    std::cout << "Heap Time " << float(dt)/CLOCKS_PER_SEC << " sec\n"; 
}