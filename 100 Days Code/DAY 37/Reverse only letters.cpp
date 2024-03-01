//! Reverse only letters (Leetcode 917)

// Question Link:
// https://leetcode.com/problems/reverse-only-letters/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string reverseOnlyLetters(string s) {
    string str = "";
    vector<int> pos;
    for (int i = 0; i < s.length(); i++) {
        if (isalpha(s[i]))
            str = str + s[i];
        else
            pos.push_back(i);
    }
    reverse(str.begin(), str.end());
    for (int i = 0; i < pos.size(); i++) {
        str.insert(pos[i], sizeof(char), s[pos[i]]);
    }
    return str;
}

int main() {
    string s;
    cin >> s;
    cout << reverseOnlyLetters(s) << endl;
    return 0;
}

// scan entire string and make a string which contains letters
// store non-letter indices in a vector
// reverse that string
// now insert non-letters in their position
// return that