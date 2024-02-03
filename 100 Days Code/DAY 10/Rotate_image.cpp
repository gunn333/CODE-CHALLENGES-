//! Rotate Image

#include <bits/stdc++.h>
using namespace std;
void rotate(vector<vector<int>> &matrix) {
  int n = matrix.size();
  int m = matrix[0].size();
  // Transpose Of Matrix
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      swap(matrix[i][j], matrix[j][i]);
    }
  }
  // Row-wise reverse
  for (int i = 0; i < n; i++) {
    reverse(matrix[i].begin(), matrix[i].end());
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> arr(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }
  rotate(arr);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}