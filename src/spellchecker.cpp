/*----------------------------------------------------------
 * Spellchecker using Soundex Algorithm, developing each run case
 * for each file and checks it's soundex string, mapping all suggestions
 * of each word.
 *
 * Github Repo -> https://github.com/a01754574/Spellchecker
 * Project Specs -> https://arielortiz.info/apps/s202213/tc1031/integrating_project/
 *
 * 30-Nov-2022
 *
 * Developed by:
 *      A01754574 Luis Fernando De Leon Silva
 *      A01754461 Gael Alejandro Morales Rodriguez
 *
 * Instituto Tecnologico de Estudios Superiores de Monterrey
 *----------------------------------------------------------*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_mao>
#include <unordered_set>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <regex>

using namespace std;

const int len_soundex = 7;

// Unordered_set and unordered_map for init
unordered_map<char, char> parse_values = {
        {'b', '1'}, {'f', '1'}, {'p', '1'}, {'v', '1'},
        {'c', '2'}, {'g', '2'}, {'j', '2'}, {'k', '2'}, {'q', '2'}, {'s', '2'}, {'x', '2'}, {'z', '2'},
        {'d', '3'}, {'t', '3'},
        {'l', '4'},
        {'m', '5'}, {'n', '5'},
        {'r', '6'}
};

unordered_set<char> parse_ignore {'a', 'e', 'i', 'o', 'u', 'h', 'w', 'y'};

// Unordered_set and unordered_map for main



/***  Initialize Methods ***/

auto soundex(const string& token) {
    string token = transform(token.begin(), token.end(), token.begin(), ::tolower);
    string soundex_word = "";

    soundex_word += token[0];

    for (int i = 1; i < token.size(); i++) {
        if (not parse_ignore.count(token[i])) {
            soundex_word += parse_values[token[i]];
        }
    }

    soundex_word += "0000000";
    soundex_word = soundex_word.substr(0, len_soundex);

    return soundex_word;
}

struct word {
    string text;
    int line;
    int column;
};

bool read_words(const string input_file_name, vector<word>& words) {
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