//! Longest Ideal Subsequence (Leetcode 2370)

// Question Link:
// https://leetcode.com/problems/longest-ideal-subsequence/

#include <bits/stdc++.h>
using namespace std;

int longestIdealString(string s, int k) {
  vector<int> v(26, 0);
  int ans = 0;
  for (int i = s.size() - 1; i >= 0; i--) {
    int cnt = 0;
    for (int j = s[i] - 'a' - k; j <= s[i] - 'a' + k; ++j) {
      if (j >= 0 && j < 26)
        cnt = max(cnt, v[j]);
    }
    v[s[i] - 'a'] = cnt + 1;
    ans = max(ans, v[s[i] - 'a']);
  }
  return ans;
}

int main() {
  // Test case 1
  string s = "abcde";
  int k = 1;
  cout << longestIdealString(s, k) << endl;
  // Test case 2
  s = "ab";
  k = 2;
  cout << longestIdealString(s, k) << endl;
  return 0;
}