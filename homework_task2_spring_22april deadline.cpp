#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>

void merge(std::vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& arr, int l, int r) {
    if (l >= r)
        return;

    int m = l + (r - l) / 2;

    if (r - l < 1000) { // ѕорог дл€ последовательной сортировки
        std::sort(arr.begin() + l, arr.begin() + r + 1);
    }
    else {
        std::thread t1(mergeSort, std::ref(arr), l, m);
        std::thread t2(mergeSort, std::ref(arr), m + 1, r);

        t1.join();
        t2.join();

        merge(arr, l, m, r);
    }
}

int main() {
    const int size = 1000;
    std::vector<int> arr(size);

    // «аполнение массива случайными числами
    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 1000;
    }

    mergeSort(arr, 0, size - 1);

    // ¬ывод отсортированного массива
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
