//! Decode String (Leetcode 394)

// Question Link:
// https://leetcode.com/problems/decode-string/

#include <bits/stdc++.h>
using namespace std;

string decodeString(string s) {
  const char start = '[';
  const char end = ']';

  vector<char> chars;

  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == end) {
      vector<char> pattern;
      while (chars.size() > 0) {
        char c = chars.back();

        if (c == start) {
          chars.pop_back();
          break;
        }

        pattern.push_back(c);
        chars.pop_back();
      }

      string tmp("");
      while (chars.size() > 0) {
        char c = chars.back();
        if (c < '0' || c > '9') {
          break;
        }

        tmp.insert(tmp.begin(), 1, c);
        chars.pop_back();
      }

      int k(stoi(tmp));

      for (int j = 0; j < k; ++j) {
        copy(pattern.rbegin(), pattern.rend(), back_inserter(chars));
      }
    } else {
      chars.push_back(s[i]);
    }
  }

  return string(chars.begin(), chars.end());
}

int main() {
  // Test
  string s = "3[a]2[bc]";
  cout << decodeString(s) << endl;
  return 0;
}