//! Reverse Words in a String (Leetcode 557)

// Question Link:
// https://leetcode.com/problems/reverse-words-in-a-string-iii/

#include <bits/stdc++.h>
using namespace std;
string rev(string a) {
  int i = 0;
  int j = a.length() - 1;
  while (i < j) {
    swap(a[i], a[j]);
    i++;
    j--;
  }
  return a;
}
string reverseWords(string s) {
  string temp = "";
  string ans = "";
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == ' ') {
      reverse(temp.begin(), temp.end());

      ans += temp;
      ans += " ";
      temp = "";
    } else {
      temp += s[i];
    }
  }
  for (int i = s.length() - 1; i >= 0; i--) {
    if (s[i] == ' ')
      break;
    else {
      ans += s[i];
    }
  }
  return ans;
}
int main() {
  string s = "  hello world  ";
  cout << reverseWords(s);
  return 0;
}