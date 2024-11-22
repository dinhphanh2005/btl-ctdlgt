#ifndef CHECK_SPELLING_H
#define CHECK_SPELLING_H

#include <vector>
#include <string>

using namespace std;

class CheckSpelling {
private:
    vector<string> dictionary;

    vector<string> splitParagraph(const string &paragraph) const;
public:
    bool loadFile(const string &filename);

    bool isCorrect(const string &word) const;

    vector<string> checkParagraph(const string &paragraph) const;
};

#endif
