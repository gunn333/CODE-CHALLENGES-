//! Buy 2 Chocolates (LeetCode 2706)

// Question Link:
// https://leetcode.com/problems/buy-2-chocolates/

#include <bits/stdc++.h>
using namespace std;
int buyChoco(vector<int> &prices, int money) {
  int n = prices.size();
  sort(prices.begin(), prices.end());
  int units = 0;
  int spend = 0;
  int i = 0;
  while (i < n) {
    units = prices[i] + prices[i + 1];
    spend = money - units;
    i++;
    break;
  }
  if (spend >= 0)
    return spend;
  return money;
}

int main() {
  int n, money;
  cin >> n >> money;
  vector<int> prices(n);
  for (int i = 0; i < n; i++) {
    cin >> prices[i];
  }
  cout << buyChoco(prices, money) << endl;
  return 0;
}