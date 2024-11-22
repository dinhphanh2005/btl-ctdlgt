#include <iostream>
#include <string>
#include "check_spelling.h"
using namespace std;

int main() {
    CheckSpelling check_spelling;
    if (!check_spelling.loadFile("dictionary.txt")) {
        return 1;
    }

    cout << "File loaded successfully!" << endl;

    string paragraph;
    cout << "Enter a paragraph: " << endl;
    cin.ignore();
    getline(cin, paragraph);

    auto misspell = check_spelling.checkParagraph(paragraph);

    if (misspell.empty()) {
        cout << "No words to correct!";
    } else {
        cout << "These are misspell words: ";
        for (const auto &word: misspell) {
            cout << "- " << word << endl;
        }
    }

    return 0;
}
