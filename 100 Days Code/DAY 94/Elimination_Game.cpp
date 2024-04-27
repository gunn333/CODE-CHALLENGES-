//! Elimination Game (LeetCode 390)

// Question Link:
// https://leetcode.com/problems/elimination-game/

#include <bits/stdc++.h>
using namespace std;

int lastRemaining(int n) {
  if (n == 1)
    return 1;
  int ans = 2;
  int mod = 2;
  vector<int> v;
  while (n != 1) {
    v.push_back(n);
    n /= 2;
  }
  for (int i = 1; i < v.size(); i++) {
    if (i % 2 == 1) {
      if (v[i] % 2 == 1)
        ans += mod;
    } else {
      ans += mod;
    }
    mod *= 2;
  }
  return ans;
}

int main() {
  // Test
  int n = 9;
  cout << lastRemaining(n) << endl;
  return 0;
}