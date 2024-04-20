//! Union of Two Sorted Arrays

#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
  vector<int> res;
  unordered_set<int> S;
  for (int i = 0; i < n; i++) {
    S.insert(arr1[i]);
  }
  for (int i = 0; i < m; i++) {
    S.insert(arr2[i]);
  }

  for (auto x : S) {
    res.push_back(x);
  }

  sort(res.begin(), res.end());
  return res;
}

int main() {
  int arr1[] = {1, 2, 3, 4, 5};
  int arr2[] = {1, 2, 3};
  int n = sizeof(arr1) / sizeof(arr1[0]);
  int m = sizeof(arr2) / sizeof(arr2[0]);
  vector<int> res = findUnion(arr1, arr2, n, m);
  for (int x : res) {
    cout << x << " ";
  }
  return 0;
}