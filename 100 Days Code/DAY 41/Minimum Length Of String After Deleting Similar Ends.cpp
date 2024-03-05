//! Minimum Length Of String After Deleting Similar Ends (leetcode 1750)

// Question Link:
// https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/

#include <bits/stdc++.h>
using namespace std;

int minimumLength(string s) {
  int left = 0, right = s.size() - 1;
  //   Iterating through the string from both ends
  while (left < right) {
    //  If the characters at the left and right ends are not equal, break the
    //  loop
    /*
    This is because if the characters at the left and right ends are not equal,
    then we cannot delete any more characters from the string.
     */
    if (s[left] != s[right]) {
      break;
    }
    char ch = s[left];
    while (left <= right && s[left] == ch) {
      left++;
    }
    while (left <= right && s[right] == ch) {
      right--;
    }
  }
  return max(0, right - left + 1);
}

int main() {
  string s = "ca";
  cout << minimumLength(s) << endl;
  return 0;
}