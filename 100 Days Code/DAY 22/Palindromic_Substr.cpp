//! Palibdromic Substrings (Leetcode 647)

// Question Link:
// https://leetcode.com/problems/palindromic-substrings/

#include <bits/stdc++.h>
using namespace std;
int count1 = 0;
bool isPalindrome(string s, int i, int j) {
  while (i <= j) {
    if (s[i] != s[j]) {
      return false;
      count1++;
    }
    i++;
    j--;
  }
  return true;
}
int countSubstrings(string s) {
  int count = 0;
  for (int i = 0; i < s.length(); i++) {
    for (int j = i; j < s.length(); j++) {
      if (isPalindrome(s, i, j)) {
        count++;
        if (count1 == 2) {
          break;
          count1 = 0;
        }
      }
    }
  }
  return count;
}

int main() {
  string s = "abc";
  cout << countSubstrings(s);
  return 0;
}
