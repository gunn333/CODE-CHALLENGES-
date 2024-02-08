//! Richest Customer Wealth (LeetCode - 1672)

// Question Link:
// https://leetcode.com/problems/richest-customer-wealth/

#include <iostream>
#include <vector>
using namespace std;
int maximumWealth(vector<vector<int>> &accounts) {
  int max = 0;
  for (int i = 0; i < accounts.size(); i++) {
    int sum = 0;
    for (int j = 0; j < accounts[0].size(); j++) {
      sum += accounts[i][j];
    }
    if (sum > max) {
      max = sum;
    }
  }
  return max;
}
int main() {
  vector<vector<int>> accounts = {{1, 2, 3}, {3, 2, 1}};
  cout << maximumWealth(accounts);
  return 0;
}
/*
Approach:
1. Ismein hum 2 loops chalayenge, ek loop se har customer ki wealth calculate
karenge aur dusre loop se max wealth nikalenge.
2. Har customer ki wealth calculate karne ke liye, hum ek variable sum bana
lenge
3. Sum mein har customer ki wealth add karenge aur max wealth nikalne ke liye
max variable mein sum ko store karenge agar sum max se bada hua toh.
4. Max wealth ko return karenge.
*/
