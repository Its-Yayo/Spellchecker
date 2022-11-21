#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <regex>

#include "spellchecker.h"

using namespace std;

bool read_words(
        const std::string input_file_name,
        std::vector<word>& words);

int main() {
    string file_name = "";
    vector<word> words;

    if (read_words(file_name, words)) {
        for (word w : words) {
            std::cout << w.text << "  (line " << w.line
                      << ", column " << w.column << ")\n";
        }
    } else {
        std::cout << "Unable to read file: "
                  << file_name << "\n";
    }

    return 0;
}

bool read_words(
        const string input_file_name,
        vector<word>& words) {
    ifstream input_file(input_file_name);
    if (input_file.fail()) {
        return false;
    }
    regex reg_exp("[a-zA-Z]+");
    smatch match;
    string text;
    int line = 0;
    int column = 0;
    while (getline(input_file, text)) {
        line++;
        column = 1;
        while (regex_search(text, match, reg_exp)) {
            column += match.position();
            words.push_back({match.str(), line, column});
            column += match.length();
            text = match.suffix().str();
        }
    }
    return true;
}