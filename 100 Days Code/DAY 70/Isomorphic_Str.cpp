//! Isomorphic Strings(Leetcode 205)

// Question Link:
// https://leetcode.com/problems/isomorphic-strings/

#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string str1, string str2) {
  int n = str1.size();
  int m = str2.size();
  // s1 and s2 are the strings that will be updated with the isomorphic strings
  // of str1 and str2 in simple words s1 will be the isomorphic string of str2
  string s1 = str1;
  string s2 = str2;

  // ch1 and ch2 are the characters of str1 and str2
  char ch1, ch2;
  for (int i = 0; i < n; i++) {
    ch1 = str1[i];
    ch2 = str2[i];
    for (int j = 0; j < m; j++) {
      // if ch2 is found in str2 then update the character at the same index
      if (ch2 == str2[j]) {
        // update the character at the same index in s2 with the character of
        s2[j] = ch1;
      }
      if (ch1 == str1[j]) {
        s1[j] = ch2;
      }
    }
    if (s1 == str2 && s2 == str1) {
      return true;
    }
  }
  return false;
}

int main() {
  string str1 = "egg";
  string str2 = "add";

  cout << isIsomorphic(str1, str2) << endl;

  return 0;
}