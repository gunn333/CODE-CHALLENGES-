//! K-th Smallest Prime Fraction (LeetCode 786)

// Question Link:
// https://leetcode.com/problems/k-th-smallest-prime-fraction/

#include <bits/stdc++.h>
using namespace std;

vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k) {
  vector<pair<double, pair<int, int>>> ans;

  for (int i = 0; i < arr.size(); i++) {
    double x = arr[i];
    for (int j = i + 1; j < arr.size(); j++) {
      double y = arr[j];
      ans.push_back({x / y, {arr[i], arr[j]}});
    }
  }
  sort(ans.begin(), ans.end());

  int l = ans[k - 1].second.first;
  int m = ans[k - 1].second.second;

  return {l, m};
}

int main() {
  vector<int> arr = {1, 2, 3, 5};
  int k = 3;
  vector<int> res = kthSmallestPrimeFraction(arr, k);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}