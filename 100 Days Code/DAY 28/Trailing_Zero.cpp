//! Trailing Zero in Factorial

// Question Link:
// https://leetcode.com/problems/factorial-trailing-zeroes/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>
using namespace std;

int trailingZeroes(int n) {
  int count = 0;
  while (n > 0) {
    count += n / 5; // Count multiples of 5
    n /= 5;         // Consider multiples of 5^2, 5^3, etc.
  }
  return count;
}

int main() {
  int n;
  cin >> n;
  cout << trailingZeroes(n) << endl;
  return 0;
}