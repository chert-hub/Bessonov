#include <iostream>
#include <set>
#include <string>
#include <unordered_set>

bool searchElement(const std::unordered_set<std::string>& words, const std::string& word) {
    return words.find(word) != words.end();
}

int main() {
    std::unordered_set<std::string> words;
    std::set<std::string> duplicate_words;

    std::string word;
    while (std::cin >> word) {
        if (searchElement(words, word)) {
            duplicate_words.insert(word);
        }
        else {
            words.insert(word);
        }
    }

    for (const auto& word : duplicate_words) {
        std::cout << word << "\n";
    }

    return 0;
}
