#include <iostream>
#include <vector>
#include <algorithm>

void SplitAndSort(std::vector<int>& original, std::vector<int>& positive, std::vector<int>& negative) {
    for (int num : original) {
        if (num >= 0) {
            positive.push_back(num);
        }
        else {
            negative.push_back(num);
        }
    }

    std::sort(positive.begin(), positive.end());
    std::sort(negative.begin(), negative.end());
}

int main() {
    std::vector<int> original = { 3, -5, 2, -8, 7, -1 };
    std::vector<int> positive;
    std::vector<int> negative;

    SplitAndSort(original, positive, negative);

    std::cout << "Positive elements sorted: ";
    for (int num : positive) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    std::cout << "Negative elements sorted: ";
    for (int num : negative) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}
