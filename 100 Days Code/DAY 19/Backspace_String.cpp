//! Backspace Compare String (Leetcode 844)

// Question Link:
// https://leetcode.com/problems/backspace-string-compare/

#include <bits/stdc++.h>
using namespace std;
bool backspaceCompare(string s, string t) {
  vector<char> s1;
  vector<char> s2;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '#') {
      if (s1.size() > 0)
        s1.pop_back();
    } else
      s1.push_back(s[i]);
  }
  for (int i = 0; i < t.size(); i++) {
    if (t[i] == '#') {
      if (s2.size() > 0)
        s2.pop_back();
    } else
      s2.push_back(t[i]);
  }
  if (s1.size() != s2.size())
    return false;
  for (int i = 0; i < s1.size(); i++) {
    if (s1[i] != s2[i])
      return false;
  }
  return true;
}

int main() {
  string s, t;
  cin >> s >> t;
  cout << backspaceCompare(s, t) << endl;
  return 0;
}