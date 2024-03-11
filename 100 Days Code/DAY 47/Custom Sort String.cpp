//! Custom Sort String (LeetCode 791)

// Question Link:
// https://leetcode.com/problems/custom-sort-string/

#include <bits/stdc++.h>
using namespace std;

string customSortString(string order, string s) {
  string ans = "";
  for (int i = 0; i < order.size(); i++) {
    for (int j = 0; j < s.size(); j++) {
      if (order[i] == s[j]) {
        ans.push_back(s[j]);
        // marking that s[j] = '1' as we have used it
        s[j] = '1';
      }
    }
  }
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != '1')
      ans.push_back(s[i]);
  }
  return ans;
}

int main() {
  string order = "cba";
  string s = "abcd";
  cout << customSortString(order, s);
  return 0;
}