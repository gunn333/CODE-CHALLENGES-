//! Minimum Cost Of Buying Candies with Discount

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int minimumCost(vector<int> &cost) {
  sort(cost.begin(), cost.end());

  int n = cost.size();
  if (n == 1)
    return cost[0];
  int i = n - 1;
  int sum = 0;
  while (i >= 2) {
    sum += cost[i] + cost[i - 1];
    i -= 3;
  }
  while (i >= 0) {
    sum += cost[i];
    i--;
  }
  return sum;
}

int main() {
  int n;
  cin >> n;
  vector<int> cost(n);
  for (int i = 0; i < n; ++i) {
    cin >> cost[i];
  }
  cout << minimumCost(cost) << endl;
  return 0;
}