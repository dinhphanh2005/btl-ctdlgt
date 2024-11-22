#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include "check_spelling.h"

bool CheckSpelling::loadFile(const string&filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Couldn't open " << filename << endl;
        return false;
    }

    dictionary.clear();
    string word;
    while (file >> word) {
        dictionary.push_back(word);
    }

    sort(dictionary.begin(), dictionary.end());
    return true;
}

bool CheckSpelling::isCorrect(const string &word) const {
    return binary_search(dictionary.begin(), dictionary.end(), word);
}

vector<string> CheckSpelling::splitParagraph(const string &paragraph) const {
    vector<string> words;
    stringstream stream(paragraph);
    string word;

    while (stream >> word) {
        word.erase(remove_if(word.begin(), word.end(), ::ispunct));
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        words.push_back(word);
    }

    return words;
}

vector<string> CheckSpelling::checkParagraph(const string &paragraph) const {
    vector<string> misspellings;
    auto words = splitParagraph(paragraph);
    for (const auto &word: words) {
        if (!isCorrect(word)) {
            misspellings.push_back(word);
        }
    }

    return misspellings;
}
