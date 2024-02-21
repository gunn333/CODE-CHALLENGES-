//! Check if Two Strings Are Equivalent (LeetCode 1662)

// Question Link:
// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

#include <iostream>
#include <vector>
using namespace std;

bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2) {
  string one = "";
  string two = "";
  for (int i = 0; i < word1.size(); i++) {
    one += word1[i];
  }
  for (int i = 0; i < word2.size(); i++) {
    two += word2[i];
  }
  return one == two;
}

int main() {
  vector<string> word1 = {"ab", "c"};
  vector<string> word2 = {"a", "bc"};
  cout << arrayStringsAreEqual(word1, word2) << endl; // Output: true
  return 0;
}