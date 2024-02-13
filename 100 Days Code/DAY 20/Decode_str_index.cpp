//! Decode the string at index (LeetCode 880)

// Question Link:
// https://leetcode.com/problems/decoded-string-at-index/

#include <iostream>
using namespace std;
string decodeAtIndex(string s, int k) {
  long long length = 0;
  int n = s.size();
  // length of the decoded string without actually decoding it
  for (int i = 0; i < n; ++i) {
    if (isalpha(s[i])) {
      length++;
    } else {
      length *= (s[i] - '0');
    }
  }

  // finding the kth character
  for (int i = n - 1; i >= 0; --i) {
    k %= length;
    if (k == 0 && isalpha(s[i])) {
      return string(1, s[i]);
    }

    if (isdigit(s[i])) {
      length /= (s[i] - '0');
    } else {
      length--;
    }
  }

  return "";
}

int main() {
  string s = "leet2code3";
  int k = 10;
  cout << decodeAtIndex(s, k);
  return 0;
}
