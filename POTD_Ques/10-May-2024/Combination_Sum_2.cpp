//! Combination Sum II (GeeksForGeeks)

// Question Link:
// https://practice.geeksforgeeks.org/problems/combination-sum-ii-1587115620/1

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> CombinationSum2(vector<int> arr, int n, int k) {
  // The result vector pair will store the final combinational sum pairs
  vector<vector<int>> res;
  sort(arr.begin(), arr.end());
  vector<int> v;
  int sum = 0;
  int index = 0;
  CombinationSum2Util(arr, n, k, index, sum, v, res);
  return res;
}

void CombinationSum2Util(vector<int> arr, int n, int k, int index, int sum,
                         vector<int> &v, vector<vector<int>> &res) {
  if (sum == k) {
    res.push_back(v);
    return;
  }
  if (sum > k) {
    return;
  }
  for (int i = index; i < n; i++) {
    if (i > index && arr[i] == arr[i - 1]) {
      continue;
    }
    v.push_back(arr[i]);
    CombinationSum2Util(arr, n, k, i + 1, sum + arr[i], v, res);
    v.pop_back();
  }
}