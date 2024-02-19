//! Length of the longest substring without repeating characters (Leetcode 3.)

// Question Link:
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
  int ma = 0;
  int i = 0;
  int j = 0;
  set<char> st;
  while (i < s.length()) {
    if (st.find(s[i]) == st.end()) {
      st.insert(s[i]);
      int len = st.size();
      ma = max(ma, len);
      i++;
    } else if (st.find(s[i]) != st.end()) {
      st.erase(s[j]);
      j++;
    }
  }
  return ma;
}

int main() {
  string s;
  cin >> s;
  cout << lengthOfLongestSubstring(s) << endl;
  return 0;
}