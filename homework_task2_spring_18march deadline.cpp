#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

// Функция для нахождения высоты каждого элемента в генеалогическом древе
void findHeight(std::map<std::string, std::string>& familyTree, std::map<std::string, int>& heights, const std::string& current, int height) {
    heights[current] = height;
    for (const auto& entry : familyTree) {
        if (entry.second == current) {
            findHeight(familyTree, heights, entry.first, height + 1);
        }
    }
}

int main() {
    int N;
    std::cin >> N;

    std::map<std::string, std::string> familyTree;
    std::map<std::string, int> heights;

    // Считываем отношения родитель-потомок
    for (int i = 0; i < N - 1; ++i) {
        std::string child, parent;
        std::cin >> child >> parent;
        familyTree[child] = parent;
    }

    // Находим высоту каждого элемента
    for (const auto& entry : familyTree) {
        if (entry.second.empty()) { // Если это родоначальник
            findHeight(familyTree, heights, entry.first, 0);
        }
    }

    // Выводим элементы в лексикографическом порядке с их высотой
    for (const auto& entry : heights) {
        std::cout << entry.first << " " << entry.second << std::endl;
    }

    return 0;
}
