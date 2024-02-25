//! Palindrome Number (LeetCode 9)

// Question Link:
// https://leetcode.com/problems/palindrome-number/

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int x) {
  string str = to_string(x);
  int n = str.size();
  for (int i = 0, j = n - 1; i <= j; i++, j--) {
    if (str[i] != str[j]) {
      return false;
    }
  }
  return true;
}

int main() {
  int x = 121;
  cout << isPalindrome(x) << endl;
  return 0;
}