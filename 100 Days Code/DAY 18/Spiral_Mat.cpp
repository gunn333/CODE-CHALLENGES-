//! Spiral Matrix Problem (LeetCode 54)

// Question Link:
// https://leetcode.com/problems/spiral-matrix/

#include <bits/stdc++.h>
using namespace std;
vector<int> spiralOrder(vector<vector<int>> &matrix) {
  int row = matrix.size() - 1;
  int col = matrix[0].size() - 1;
  vector<int> v;
  int sr = 0, sc = 0, er = row, ec = col;

  while (v.size() != ((row + 1) * (col + 1))) {
    for (int i = sc; i <= ec; i++) {
      v.push_back(matrix[sr][i]);
    }
    sr++;

    if (v.size() == ((row + 1) * (col + 1)))
      break;
    for (int i = sr; i <= er; i++) {
      v.push_back(matrix[i][ec]);
    }
    ec--;

    if (v.size() == ((row + 1) * (col + 1)))
      break;
    for (int i = ec; i >= sc; i--) {
      v.push_back(matrix[er][i]);
    }
    er--;

    if (v.size() == ((row + 1) * (col + 1)))
      break;
    for (int i = er; i >= sr; i--) {
      v.push_back(matrix[i][sc]);
    }
    sc++;
  }
  return v;
}

int main() {
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<int> v = spiralOrder(matrix);
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  return 0;
}