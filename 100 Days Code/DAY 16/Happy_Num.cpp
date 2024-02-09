//! Happy Number (LeetCode - 202)

// Question Link:
// https://leetcode.com/problems/happy-number/

#include <bits/stdc++.h>
using namespace std;
bool isHappy(int n) {
  unordered_set<int> s;
  int x = 0;
  while (s.count(n) == 0) {
    s.insert(n);
    x = 0;
    while (n) {
      x += (n % 10) * (n % 10);
      n /= 10;
    }
    n = x;
  }
  return (n == 1);
}
int main() {
  int n = 19;
  cout << isHappy(n) << endl;
  return 0;
}