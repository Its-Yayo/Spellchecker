#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int len_soundex = 7;

static unordered_map<char, char> parse_values = {
        {'b', '1'}, {'f', '1'}, {'p', '1'}, {'v', '1'},
        {'c', '2'}, {'g', '2'}, {'j', '2'}, {'k', '2'}, {'q', '2'}, {'s', '2'}, {'x', '2'}, {'z', '2'},
        {'d', '3'}, {'t', '3'},
        {'l', '4'},
        {'m', '5'}, {'n', '5'},
        {'r', '6'}
};

auto soundex(const string& s) {

}