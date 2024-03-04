//! Divide 2 Integers (Leetcode 29)

// Question Link:
// https://leetcode.com/problems/divide-two-integers/

#include <bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor) {
  double ans = (double)dividend / divisor;
//   ans > INT_MAX yeah 
  if (ans > INT_MAX) {
    return INT_MAX;
  } else if (ans < INT_MIN) {
    return INT_MIN;
  }
  return ans;
}

int main() {
  int dividend, divisor;
  cin >> dividend >> divisor;
  cout << divide(dividend, divisor) << endl;
  return 0;
}