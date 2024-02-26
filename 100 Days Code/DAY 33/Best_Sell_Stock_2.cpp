//! Best Time to Buy and Sell Stock II

// Question Link:
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices) {
  int n = prices.size();
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) {
    v.push_back(make_pair(prices[i], i));
  }
  sort(v.begin(), v.end());
  int sum = 0;
  for (int i = 1; i < v.size(); i++) {
    if (v[i].first > v[i - 1].first && v[i].second > v[i - 1].second) {
      sum += v[i].first - v[i - 1].first;
      ;
    }
  }
  return sum;
}

int main() {
  int n;
  cin >> n;
  vector<int> prices(n);
  for (int i = 0; i < n; i++) {
    cin >> prices[i];
  }
  cout << maxProfit(prices) << endl;
  return 0;
}