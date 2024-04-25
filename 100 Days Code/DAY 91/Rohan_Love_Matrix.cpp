//! Rohan's Love for Matrix

// Question Link:
// https://www.geeksforgeeks.org/problems/rohans-love-for-matrix4723/1

#include <bits/stdc++.h>
using namespace std;

int firstElement(int n) {
  // If you see a^2 , b^2, c^2 then you will see pattern like fibonacci series
  if (n < 3) {
    return 1;
  }
  // Assigning first two elements of fibonacci series as 1
  // And c(3rd element) as 0
  int a = 1, b = 1, c = 0;
  // Modulo value
  int mod = 1000000007;
  for (int i = 3; i <= n; i++) {
    c = (a + b) % mod;
    a = b;
    b = c;
  }
  return c;
}

int main() {
  int n = 5;
  cout << firstElement(n) << endl;
  return 0;
}