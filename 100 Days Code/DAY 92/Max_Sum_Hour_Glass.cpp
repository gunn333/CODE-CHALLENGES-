//! Maximium Sum of Hour Glass (GeeksForGeeks)

#include <bits/stdc++.h>
using namespace std;

int findMaxSum(int n, int m, vector<vector<int>> mat) {
  // code here
  int max_sum = INT_MIN;
  if (n < 3 || m < 3) {
    return -1;
  }
  for (int i = 0; i < n - 2; i++) {
    for (int j = 0; j < m - 2; j++) {
      int sum = mat[i][j] + mat[i][j + 1] + mat[i][j + 2] + mat[i + 1][j + 1] +
                mat[i + 2][j] + mat[i + 2][j + 1] + mat[i + 2][j + 2];
      max_sum = max(max_sum, sum);
    }
  }
  return max_sum;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> mat(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
    }
  }
  cout << findMaxSum(n, m, mat) << endl;
  return 0;
}