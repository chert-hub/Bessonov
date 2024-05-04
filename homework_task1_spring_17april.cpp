#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

// ��������� ��������� �����
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

// ��������� ���������� ����� � �������� ���������
int random_int(int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

// ���������� ��������
void merge(std::vector<int>& arr, int l, int m, int r) {
    // ���������� �������
}

void mergeSort(std::vector<int>& arr, int l, int r) {
    // ���������� ���������� ��������
}

// ������� ����������
void quickSort(std::vector<int>& arr, int low, int high) {
    // ���������� ������� ����������
}

int main() {
    const int size = 10000;
    std::vector<int> arr(size);

    // ���������� ������� ���������� �������
    for (int i = 0; i < size; ++i) {
        arr[i] = random_int(1, 10000);
    }

    // ����� ������� ��� ������� ����������
    std::vector<int> arr_quick = arr;

    // ��������� ������� ��� ���������� ��������
    auto start_merge = std::chrono::high_resolution_clock::now();
    mergeSort(arr, 0, size - 1);
    auto end_merge = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_merge = end_merge - start_merge;

    // ��������� ������� ��� ������� ����������
    auto start_quick = std::chrono::high_resolution_clock::now();
    quickSort(arr_quick, 0, size - 1);
    auto end_quick = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_quick = end_quick - start_quick;

    // ����� �����������
    if (duration_merge < duration_quick) {
        std::cout << "Merge sort is faster. Time:" << duration_merge.count() << " sekonds." << std::endl;
    }
    else {
        std::cout << "Quicksort is faster. Time:" << duration_quick.count() << " sekonds." << std::endl;
    }

    return 0;
}
