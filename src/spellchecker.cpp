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

struct word {
    string text;
    int line;
    int column;
};

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

void print_vector()

int main() {
    string file_name = "";
    vector<word> words;

    if (read_words(file_name, words)) {
        for (word w : words) {
            // Code for Soundex Function
        }
    } else {
        cout << "Unable to read file: "
                  << file_name << "\n";
    }



    return 0;

}