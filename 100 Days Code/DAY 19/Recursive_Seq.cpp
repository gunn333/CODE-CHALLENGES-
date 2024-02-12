//! Recursive Sequence (POTD - gfg)

// Question Link:
// https://www.geeksforgeeks.org/problems/recursive-sequence1611/1

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007; // 10^9 + 7

// This function will return the sum of 1 to n-1 numbers
int sum(int n) {
  int ans = 0;
  for (int i = 1; i < n; i++) {
    ans = ans + i;
  }
  return ans % MOD;
  // We are taking mod because the value of ans can be very large
}

// This function will return the product of m to m+n numbers
int product(int m, int n) {
  long long ans = 1;
  for (int i = 1; i <= n; i++) {
    ans = (ans * (m + i)) % MOD;
  }
  return ans;
}

// This function will return the recursion of the sequence
int recursion(int n) {
  if (n == 1) {
    return 1;
  } else {
    int m = sum(n);
    return (recursion(n - 1) + product(m, n)) % MOD;
  }
}

long long Sequence(int n) { return recursion(n); }

int main() {
  int n;
  cin >> n;
  cout << Sequence(n) << endl;
  return 0;
}
