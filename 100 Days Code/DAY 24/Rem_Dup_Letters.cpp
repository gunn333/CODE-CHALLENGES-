//! Remove Duplicate Letters (Leetcode 316)

// Question Link:
// https://leetcode.com/problems/remove-duplicate-letters/

#include <bits/stdc++.h>
using namespace std;
string removeDuplicateLetters(string s) {

  vector<int> cnt(26, 0), vis(26, 0);

  string res = "";
  int n = s.size();

  for (int i = 0; i < n; ++i)
    cnt[s[i] - 'a']++;

  for (int i = 0; i < n; ++i) {
    cnt[s[i] - 'a']--;

    if (!vis[s[i] - 'a']) {

      while (res.size() > 0 && res.back() > s[i] && cnt[res.back() - 'a'] > 0) {
        vis[res.back() - 'a'] = 0;
        res.pop_back();
      }

      res += s[i];
      vis[s[i] - 'a'] = 1;
    }
  }
  return res;
}

int main() {
  string s = "bcabc";
  cout << removeDuplicateLetters(s) << endl;
  return 0;
}