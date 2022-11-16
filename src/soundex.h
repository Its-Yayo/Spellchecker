#include <fstream>
#include <regex>
#include <vector>

#include <fstream>
#include <regex>
#include <vector>

using namespace std;

struct word {
    std::string text;
    int line;
    int column;
};

bool read_words(
        const string input_file_name,
        std::vector<word>& words) {
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