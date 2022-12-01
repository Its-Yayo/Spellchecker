/*----------------------------------------------------------
 * Spellchecker using Soundex Algorithm, developing each run case
 * for each file and checks it's soundex string, mapping all suggestions
 * of each word.
 *
 * Github Repo -> https://github.com/a01754574/Spellchecker
 * Project Specs -> https://arielortiz.info/apps/s202213/tc1031/integrating_project/
 *
 * Nov - 30 - 2022
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
#include <unordered_map>
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

// Const Data structures for parse Soundex words and word's file .txt
unordered_set<string> parse_words;
unordered_set<string> parse_incorrect;
unordered_map<string, vector<string>> parse_final;


vector<string> words_suggestions;

struct word {
    string text;
    int line;
    int column;
};

// Words.txt
vector<string> sound_var;
vector<word> word_file;
vector<word> word_incorrect;

/******* Initialize Methods *******/

auto soundex(string token) {
    transform(token.begin(), token.end(), token.begin(), ::tolower);
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

void add_soundex(vector<word>& words) {
    for (int i  = 0; i < words.size(); i++) {
        bool vc = parse_final.count(soundex(word_file[i].text));
        if (vc) {
            parse_final[soundex(word_file[i].text)].push_back(word_file[i].text);
        } else {
            sound_var.push_back(word_file[i].text);
            parse_final.emplace(soundex(word_file[i].text),sound_var);
        }
    }
}


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


void find_word(vector<word> words) {
    for (int i = 0; i < words.size(); i++) {
        if (parse_words.count(words[i].text) == false and parse_incorrect.count(words[i].text) == false) {
            word_incorrect.push_back(words[i]);
            parse_incorrect.emplace(words[i].text);
        }
    }
}

void add_word(vector<word> words, unordered_set<string> words_set) {
    for (int i = 0; i < words.size(); i++) {
        auto add_1 = words_set.emplace(words[i].text);
    }
}

void print_final(vector<word>& words) {
    for (auto w : words) {
        word_final = w.text
        string soundex_final = soundex(word_final);
        int _size = parse_final[soundex_final].size()
        
        cout <<
        "Unrecognized word: " << w.text <<
        "  First found at line " << w.line << ", column " <<
        w.column << "\n";
        
        if (_size <= 0) {
            cout << "No suggestions. \n";
        } else {
            bool _map = parse_final.count(soundex(word)); 

            if (not _map) {
                auto word_sugg = parse_incorrect.insert(word_spell);
                
            }
        }

    }
}

// void check_words(string file) {
//     bool rword = read_words(file_name, word_file);
//     string file_1 = "words.txt";
//     rword = read_words(file_1, word_file);
//     add_word(word_file, Words);
//     find_word(word_file);
//     add_soundex();
// }



int main(int argc, char* argv[]) {
    string file_name = "tooinkle.txt";
    vector<word> words;

    string file = argv[1];

    if (read_words(file, words)) {
        print_final(words);
    } else {
        cout << "No file found" << "\n";
    }


    return 0;
}