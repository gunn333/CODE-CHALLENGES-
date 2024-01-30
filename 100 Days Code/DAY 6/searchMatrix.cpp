//! Search Matrix

#include <bits/stdc++.h>
using namespace std;
int searchMatrix(vector<vector<int>> &matrix, int target) {
  int row_size = matrix.size();
  int col_size = matrix[0].size();
  for (int i = 0; i < row_size; i++) {
    for (int j = 0; j < col_size; j++) {
      if (matrix[i][j] == target) {
        return true;
      }
    }
    return false;
  }
}
int main() {
  int row_size, col_size;
  cin >> row_size >> col_size;
  vector<vector<int>> matrix(row_size, vector<int>(col_size));
  for (int i = 0; i < row_size; i++) {
    for (int j = 0; j < col_size; j++) {
      cin >> matrix[i][j];
    }
  }
  int target;
  cin >> target;
  int res = searchMatrix(matrix, target);
  cout << res << endl;
  return 0;
}