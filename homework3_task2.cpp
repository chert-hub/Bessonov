#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

// Ôóíêöèÿ äëÿ íàõîæäåíèÿ âûñîòû êàæäîãî ýëåìåíòà â ãåíåàëîãè÷åñêîì äðåâå
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

    // Ñ÷èòûâàåì îòíîøåíèÿ ðîäèòåëü-ïîòîìîê
    for (int i = 0; i < N - 1; ++i) {
        std::string child, parent;
        std::cin >> child >> parent;
        familyTree[child] = parent;
    }

    // Íàõîäèì âûñîòó êàæäîãî ýëåìåíòà
    for (const auto& entry : familyTree) {
        if (entry.second.empty()) { // Åñëè ýòî ðîäîíà÷àëüíèê
            findHeight(familyTree, heights, entry.first, 0);
        }
    }

    // Âûâîäèì ýëåìåíòû â ëåêñèêîãðàôè÷åñêîì ïîðÿäêå ñ èõ âûñîòîé
    for (const auto& entry : heights) {
        std::cout << entry.first << " " << entry.second << std::endl;
    }

    return 0;
}
