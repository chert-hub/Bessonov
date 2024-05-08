#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

std::string MostFrequentWord(const std::string& text) {
    std::map<std::string, int> wordCount;
    std::string word = "";
    int maxCount = 0;

    // Подсчет количества встреч каждого слова
    for (size_t i = 0; i < text.size(); ++i) {
        if (isalpha(text[i])) {
            word += tolower(text[i]);
        }
        else {
            if (!word.empty()) {
                wordCount[word]++;
                maxCount = std::max(maxCount, wordCount[word]);
                word = "";
            }
        }
    }

    if (!word.empty()) {
        wordCount[word]++;
        maxCount = std::max(maxCount, wordCount[word]);
    }

    // Находим слово(а) с максимальным количеством вхождений
    std::vector<std::string> mostFrequentWords;
    for (const auto& pair : wordCount) {
        if (pair.second == maxCount) {
            mostFrequentWords.push_back(pair.first);
        }
    }

    // Сортируем слова и выводим первое по алфавиту
    std::sort(mostFrequentWords.begin(), mostFrequentWords.end());

    return mostFrequentWords[0];
}

int main() {
    std::string text = "This is a sample text with some repeated words like sample and text.";

    std::string mostFrequent = MostFrequentWord(text);

    std::cout << "Most frequent word: " << mostFrequent << std::endl;

    return 0;
}
