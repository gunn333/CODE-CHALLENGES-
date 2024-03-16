//! Minimum Operations to make integers zero (Leetcode 2749)

// Question Link:
// https://leetcode.com/problems/minimum-operations-to-make-integers-zero/

#include <bits/stdc++.h>
using namespace std;

int countBits(long long num) {
  int count = 0;
  while (num > 0) {
    count += num & 1;
    num >>= 1;
  }
  return count;
}
int makeTheIntegerZero(int num1, int num2) {
  if (num1 < num2) {
    return -1;
  }

  for (int steps = 0; steps <= 100; steps++) {
    long long diff = num1 - 1LL * (num2)*steps;
    int bits = countBits(diff);
    if (bits <= steps && steps <= diff) {
      return steps;
    }
  }
  return -1;
}

int main() {
  int num1 = 3, num2 = 2;
  cout << makeTheIntegerZero(num1, num2);
  return 0;
}
