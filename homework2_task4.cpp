#include <iostream>
#include <stack>
#include <string>

bool isValidBracketSequence(const std::string& sequence) {
    std::stack<char> brackets;

    for (char bracket : sequence) {
        if (bracket == '(' || bracket == '[' || bracket == '{') {
            brackets.push(bracket);
        }
        else if (bracket == ')' || bracket == ']' || bracket == '}') {
            if (brackets.empty()) {
                return false;
            }

            char openBracket = brackets.top();
            brackets.pop();

            if ((openBracket == '(' && bracket != ')') ||
                (openBracket == '[' && bracket != ']') ||
                (openBracket == '{' && bracket != '}')) {
                return false;
            }
        }
    }

    return brackets.empty();
}

int main() {
    std::string sequence = "([]{()})";

    if (isValidBracketSequence(sequence)) {
        std::cout << "The bracket sequence is valid." << std::endl;
    }
    else {
        std::cout << "The bracket sequence is invalid." << std::endl;
    }

    return 0;
}
