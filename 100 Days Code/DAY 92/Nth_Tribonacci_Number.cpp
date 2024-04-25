//! Nth Tribonacci Number (LeetCode 1137)

// Question Link:
// https://leetcode.com/problems/n-th-tribonacci-number/

#include <bits/stdc++.h>
using namespace std;

int tribonacci(int n) {
  if (n == 0) {
    return 0;
  }
  // If n is less than 3 means the third element is 1
  if (n < 3) {
    return 1;
  }
  // Assigning first three elements of tribonacci series as 0, 1, 1
  int firstnum = 0, secondnum = 1, thirdnum = 1;
  for (int i = 3; i <= n; i++) {
    // Adding first three elements in temp
    int temp = firstnum + secondnum + thirdnum;
    firstnum = secondnum;
    secondnum = thirdnum;
    thirdnum = temp;
  }
  return thirdnum;
}

int main() {
  int n = 5;
  cout << tribonacci(n) << endl;
  return 0;
}
