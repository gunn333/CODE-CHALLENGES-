//! Valid Parentheses (Leetcode 20)

// Question Link:
// https://leetcode.com/problems/valid-parentheses/

#include <bits/stdc++.h>
using namespace std;
vector<char> vec;
bool isValid(string s) {
  for (int i = 0; i < s.length(); i++) {
    // if its an opening parenthesis
    if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
      vec.push_back(s[i]);
    }
    // if its closing
    else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
      if (vec.empty()) {
        return false;
      }
      // check which closing it is
      if (s[i] == ')') {
        // then check if it matches in the vector, and pop the last element of
        // the vector if it is
        if ('(' == vec.back()) {
          vec.pop_back();
        } else {
          return false;
        }
      }
      if (s[i] == ']') {
        if ('[' == vec.back()) {
          vec.pop_back();
        } else {
          return false;
        }
      }
      if (s[i] == '}') {
        if ('{' == vec.back()) {
          vec.pop_back();
        } else {
          return false;
        }
      }
    }
  }
  // after for loop, if vector is empty, string is valid
  if (vec.empty()) {
    return true;
  } else {
    return false;
  }
}
int main() {
  string s;
  cin >> s;
  cout << isValid(s);
  return 0;
}