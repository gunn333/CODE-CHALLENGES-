//! Reverse Words in a given string

// Question Link:
// https://www.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1?page=1&difficulty%5B%5D=0&category%5B%5D=Strings&sortBy=submissions

#include <iostream>
#include <string>
#include <vector>
using namespace std;
string reverseWords(string S) {
  string words = "";
  string ans = "";

  for (int i = 0; i < S.length(); i++) {
    if (S[i] != '.') {
      words += S[i];
    }
    if (S[i] == '.') {
      words = S[i] + words;
      ans = words + ans;
      words = "";
    }
    if (i == S.length() - 1) {
      ans = words + ans;
    }
  }
  return ans;
}

int main() {
  string str;
  cin >> str;
  cout << reverseWords(str);
  return 0;
}