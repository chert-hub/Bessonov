#include <iostream>
#include <vector>
#include <string>

template <typename T>
void Print(const T& container, const std::string& delimiter) {
    auto it = container.begin();
    if (it != container.end()) {
        std::cout << *it;
        ++it;
    }
    for (; it != container.end(); ++it) {
        std::cout << delimiter << *it;
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> data = { 1, 2, 3 };
    Print(data, ", ");  // Output: 1, 2, 3
    return 0;
}
