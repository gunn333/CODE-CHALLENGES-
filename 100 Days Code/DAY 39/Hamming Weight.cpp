//! Hamming Weight (LeetCode 191)

// Question Link:
// https://leetcode.com/problems/number-of-1-bits/

#include <bits/stdc++.h>
using namespace std;

int hammingWeight(uint32_t n) {
  int ans = 0;
  while (n) {
    if (n & 1) {
      ans++;
    }
    n = n >> 1;
  }
  return ans;
}

int main() {
  uint32_t n;
  cin >> n;
  cout << hammingWeight(n);
  return 0;
}