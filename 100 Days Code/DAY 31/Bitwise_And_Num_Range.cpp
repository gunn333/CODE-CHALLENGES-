//! Bitwise AND of Numbers Range (Leetcode 201)

// Question Link:
// https://leetcode.com/problems/bitwise-and-of-numbers-range/

#include <bits/stdc++.h>
using namespace std;

int rangeBitwiseAnd(int left, int right) {
  if (left == right)
    return left;
  for (int i = 0; i <= 30; i++) {
    if (left >= pow(2, i) && right < pow(2, i + 1)) {
      int l = pow(2, i), r = pow(2, i + 1) - 1;
      int mid;
      while (l <= left && r >= right) {
        mid = l + (r - l) / 2;
        if (left <= mid)
          r = mid;
        else
          l = mid + 1;
      }
      return l;
    }
  }
  return 0;
}

int main() {
  int left, right;
  cin >> left >> right;
  cout << rangeBitwiseAnd(left, right) << endl;
  return 0;
}