//! Find First Palindrome String in a given string  (LeetCode 336)

// Question Link:
// https://leetcode.com/problems/find-first-palindromic-string-in-the-array/?envType=daily-question&envId=2024-02-13

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool checkPalindrome(string S) {
  int i = 0, j = S.size() - 1;
  while (i <= j) {
    if (S[i] != S[j])
      return false;
    i++;
    j--;
  }
  return true;
}

string firstPalindrome(vector<string> &words) {
  for (int i = 0; i < words.size(); i++) {
    if (checkPalindrome(words[i])) {
      return words[i];
    }
  }
  return "";
}

int main() {
  vector<string> words = {"abcd", "dcba", "lls", "s", "sssll"};
  cout << firstPalindrome(words);
  return 0;
}