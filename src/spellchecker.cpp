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
        const std::string input_file_name,
        std::vector<word>& words) {
    



}