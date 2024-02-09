// ! Index of the first occurrence in a string - LeetCode - 28

// Question Link:
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

#include <bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle) {
  int index = -1;
  bool flag = false;
  for (int i = 0; i < haystack.size(); i++) {
    for (int j = 0; j < needle.size(); j++) {
      if (haystack[i + j] == needle[j]) {
        if (j == needle.size() - 1) {
          index = i;
          flag = true;
        }
        continue;
      } else if (haystack[i + j] != needle[j]) {
        break;
      }
    }
    if (flag == true) {
      break;
    }
  }
  return index;
}

int main() {
  string haystack = "hello";
  string needle = "ll";
  cout << strStr(haystack, needle) << endl;
  return 0;
}