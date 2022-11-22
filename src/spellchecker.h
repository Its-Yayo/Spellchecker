#include <iostream>
#include <stdio.h>
#include <string>
#include <bits/stdc++.h>
#include <cctype>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

const int len_soundex = 7;

unordered_map<char, char> parse_values = {
        {'b', '1'}, {'f', '1'}, {'p', '1'}, {'v', '1'},
        {'c', '2'}, {'g', '2'}, {'j', '2'}, {'k', '2'}, {'q', '2'}, {'s', '2'}, {'x', '2'}, {'z', '2'},
        {'d', '3'}, {'t', '3'},
        {'l', '4'},
        {'m', '5'}, {'n', '5'},
        {'r', '6'}
};

unordered_set<char> parse_ignore {'a', 'e', 'i', 'o', 'u', 'h', 'w', 'y'};

auto soundex(const string& token) {
    string token = transform(token.begin(), token.end(), token.begin(), ::tolower);
    string soundex_word = "";

    soundex_word += token[0];

    for (int i = 1; i < token.size(); i++) {
        if (not parse_ignore.count(token[i])) {
            soundex_word += parse_values[token[i]];
        }
    }

    if ()

    return soundex_word;
}