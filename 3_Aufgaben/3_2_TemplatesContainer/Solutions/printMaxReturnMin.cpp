#include <iostream>

template <typename T>
T const &printMaxReturnMin(const T &lhs, const T &rhs) {
    T max;
    if (lhs > rhs) {
        max = lhs;
    } else {
        max = rhs;
    }
    std::cout << "max of the two is: " << max << std::endl;
    
    return lhs < rhs ? lhs : rhs;
}

// Testen der Template Funktion

int main () {
  int i = 39;
  int j = 20;
  auto k = printMaxReturnMin(i,j);

  double a = 13.5;
  double b = 20.7;
  auto c = printMaxReturnMin(a,b);
}