//! Power of 4 (Leetcode 342)

// Question Link:
// https://leetcode.com/problems/power-of-four/

#include <bits/stdc++.h>
using namespace std;
bool isPowerOfFour(int n) {
  for (int i = 0; i <= 15; i++) {
    int powerOfFour = pow(4, i);

    // If we find a power of four equal to 'n', return true
    if (powerOfFour == n)
      return true;

    // If the current power of four is greater than 'n', there's no need
    // to continue
    if (powerOfFour > n)
      return false;
  }

  // 'n' is not a power of four
  return false;
}

int main() {
  int n;
  cin >> n;
  cout << isPowerOfFour(n) << endl;
  return 0;
}