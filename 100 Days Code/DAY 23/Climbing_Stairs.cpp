//! Climbing Stairs (LeetCode 70)

// Question link:
// https://leetcode.com/problems/climbing-stairs/

#include <bits/stdc++.h>
using namespace std;
int climbStairs(int n) {
  if (n <= 3) {
    return n;
  }

  int cal = 0, temp;
  vector<int> s(n, 0);

  s[0] = 1;
  s[1] = 2;
  s[2] = 3;

  for (int i = 3; i < n; i++) {
    cal = s[i - 2] + s[i - 1];
    s[i] = cal;
  }
  return s[n - 1];
}

int main() {
  int n;
  cin >> n;
  cout << climbStairs(n);
  return 0;
}