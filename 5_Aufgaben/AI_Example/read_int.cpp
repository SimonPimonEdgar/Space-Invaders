// A small program that reads a single int in and writes this to output.
// Compile with: g++ -Wall -Wextra -pedantic -std=c++11 -o read_int read_int.cpp

#include <iostream>

int main()
{
    int i = 0;
    std::cout << "Please enter an integer: ";
    std::cin >> i;
    std::cout << "The integer you entered is: " << i << std::endl;
    return 0;
}
