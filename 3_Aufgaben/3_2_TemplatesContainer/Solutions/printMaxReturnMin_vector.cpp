#include <iostream>
#include <vector>

template <typename T>
T printMaxReturnMin(const std::vector<T>& elems) {
    T max = elems[0];
    T min = elems[0];
    for (const auto& elem : elems) {
        if (elem > max) {
            max = elem;
        }
        if (elem < min) {
            min = elem;
        }
    }
    std::cout << "max of the elements is: " << max << std::endl;

    return min;
}

int main() {
    // Test with ints
    std::vector<int> intVec{ 4, 7, 2, 9, 1 };
    int smallestInt = printMaxReturnMin(intVec);
    std::cout << "smallest int is: " << smallestInt << std::endl;

    // Test with floats
    std::vector<float> floatVec{ 3.14f, 1.618f, 2.718f, 0.123f };
    float smallestFloat = printMaxReturnMin(floatVec);
    std::cout << "smallest float is: " << smallestFloat << std::endl;

    return 0;
}