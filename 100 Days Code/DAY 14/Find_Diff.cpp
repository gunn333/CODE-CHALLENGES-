//! Find the Difference LeeCode 389.

// Question Link:
// https://leetcode.com/problems/find-the-difference/description/

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
char findTheDifference(string s, string t) {
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  for (int i = 0; i < s.length(); i++) {
    if (s[i] != t[i]) {
      return t[i];
    }
  }
  // s.length() isliye kiya hai kyunki agar s ki length t se choti hai toh
  return t[s.length()];
}
int main() {
  string s = "abcd";
  string t = "abcde";
  cout << findTheDifference(s, t) << endl;
  return 0;
}