#include <iostream>
#include <unordered_set>

int calculateSquareSum(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

bool isHappyNumber(int n) {
    std::unordered_set<int> seen;

    while (n != 1 && seen.find(n) == seen.end()) {
        seen.insert(n);
        n = calculateSquareSum(n);
    }

    return n == 1;
}

int main() {
    int number = 19; // Change this number to test different cases

    if (isHappyNumber(number)) {
        std::cout << number << " is a happy number." << std::endl;
    }
    else {
        std::cout << number << " is not a happy number." << std::endl;
    }

    return 0;
}
