#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <numeric>

void findSumOfThreeLargest(const std::vector<int>& arr, int& sum, int start, int end) {
    std::vector<int> localCopy(arr.begin() + start, arr.begin() + end);
    std::sort(localCopy.rbegin(), localCopy.rend());
    int localSum = std::accumulate(localCopy.begin(), localCopy.begin() + 3, 0);

    sum += localSum;
}

int main() {
    const int size = 1000;
    const int numThreads = 4;
    std::vector<int> arr(size);

    // Заполнение массива случайными числами
    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 1000;
    }

    int sum = 0;
    std::vector<std::thread> threads;

    // Создание и запуск потоков
    for (int i = 0; i < numThreads; ++i) {
        int start = i * (size / numThreads);
        int end = (i == numThreads - 1) ? size : (i + 1) * (size / numThreads);
        threads.push_back(std::thread(findSumOfThreeLargest, std::ref(arr), std::ref(sum), start, end));
    }

    // Дождаться завершения всех потоков
    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Sum of the three largest elements: " << sum << std::endl;

    return 0;
}
