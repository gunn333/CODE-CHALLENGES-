//! Ugly Number (leetcode 263)

// Question Link:
// https://leetcode.com/problems/ugly-number/

#include <bits/stdc++.h>
using namespace std;

bool isUgly(int num) {
  if (num <= 0) {
    return false;
  }
  if (num == 1) {
    return true;
  }
  vector<int> div(3);
  div[0] = 2, div[1] = 3, div[2] = 5;
  for (int i = 0; i < 3; i++)
    while (num % div[i] == 0)
      num = num / div[i];
  if (num == 1)
    return true;
  return false;
}

int main() {
  int num = 14;
  cout << isUgly(num) << endl;
  return 0;
}