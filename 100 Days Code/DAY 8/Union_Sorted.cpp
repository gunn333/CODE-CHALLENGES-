//! Union of two sorted arrays

#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
  set<int> s;
  for (int i = 0; i < n; i++) {
    s.insert(arr1[i]);
  }
  for (int i = 0; i < m; i++) {
    s.insert(arr2[i]);
  }
  vector<int> vec(s.begin(), s.end());

  return vec;
}

int main() {
  int n, m;
  cin >> n >> m;
  int arr1[n], arr2[m];
  for (int i = 0; i < n; i++) cin >> arr1[i];
  for (int i = 0; i < m; i++) cin >> arr2[i];

  vector<int> ans = findUnion(arr1, arr2, n, m);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}