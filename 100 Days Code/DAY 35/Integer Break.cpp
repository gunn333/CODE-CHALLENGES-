//! Integer Break (Leetcode 343)

// Question Link:
// https://leetcode.com/problems/integer-break/description/?envType=daily-question&envId=2024-02-28

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int integerBreak(int n) {
  if (n == 2)
    return 1;
  if (n == 3)
    return 2;

  long v1 = 0;
  if (n % 3 == 0)
    v1 = pow(3, n / 3);
  else if (n % 3 == 1)
    v1 = pow(3, n / 3 - 1) * 4;
  else
    v1 = pow(3, n / 3) * 2;

  return v1;
}

int main() {
  int n;
  cin >> n;
  cout << integerBreak(n) << endl;
  return 0;
}
