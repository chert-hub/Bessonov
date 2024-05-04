#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

// ������� ��� ���������� ������ ������� �������� � ��������������� �����
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

    // ��������� ��������� ��������-�������
    for (int i = 0; i < N - 1; ++i) {
        std::string child, parent;
        std::cin >> child >> parent;
        familyTree[child] = parent;
    }

    // ������� ������ ������� ��������
    for (const auto& entry : familyTree) {
        if (entry.second.empty()) { // ���� ��� �������������
            findHeight(familyTree, heights, entry.first, 0);
        }
    }

    // ������� �������� � ������������������ ������� � �� �������
    for (const auto& entry : heights) {
        std::cout << entry.first << " " << entry.second << std::endl;
    }

    return 0;
}
