//! Palindrome string

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int isPalindrome(string S) {
  int n = S.length();
  for (int i = 0, j = n - 1; i < j; i++, j--) {
    if (S[i] != S[j]) {
      return false;
    }
  }
  return true;
}
int main() {
  string str;
  cin >> str;
  cout << isPalindrome(str);
  return 0;
}