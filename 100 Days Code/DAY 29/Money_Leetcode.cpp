//! Money in Leetcode Bank (Leetcode 2043)

// Question Link:
// https://leetcode.com/problems/calculate-money-in-leetcode-bank/description/?envType=daily-question&envId=2024-02-21

#include <bits/stdc++.h>
using namespace std;
int totalMoney(int n) {
  int money = 0;
  int week = 0;
  for (int i = 0; i < n; i++) {
    if (i % 7 == 0) {
      week++;
    }
    money += week + (i % 7);
  }
  return money;
}
int main() {
  // Test cases
  cout << totalMoney(4) << endl;  // Output: 10
  cout << totalMoney(10) << endl; // Output: 37
  return 0;
}