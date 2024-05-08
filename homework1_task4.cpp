#include <iostream>
#include <vector>

void factorialNumberRepresentation(int n) {
    std::vector<int> factorials = { 1 }; // Initialize factorials array with 1

    int factorial = 1;
    while (factorial <= n) {
        factorials.push_back(factorial);
        factorial *= factorials.size(); // Calculate next factorial
    }

    for (int i = factorials.size() - 1; i >= 1; --i) {
        int digit = n / factorials[i];
        n %= factorials[i];
        for (int j = 0; j < digit; ++j) {
            std::cout << i << ".";
        }
    }
    std::cout << "0" << std::endl; // Print the last digit
}

int main() {
    int number = 463; // Change this number to test different cases

    std::cout << "Factorial representation of " << number << " is: ";
    factorialNumberRepresentation(number);

    return 0;
}
