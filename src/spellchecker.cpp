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