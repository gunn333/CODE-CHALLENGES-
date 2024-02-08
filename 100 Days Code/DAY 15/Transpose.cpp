//! Transpose of a matrix (LeetCode - 867)

// Question Link:
// https://leetcode.com/problems/transpose-matrix/

#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> transpose(vector<vector<int>> &matrix) {
  int n = matrix.size();
  int m = matrix[0].size();

  //   2D vector result with size m*n and all elements initialized to 0
  vector<vector<int>> result(m, vector<int>(n, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {

      result[j][i] = matrix[i][j];
    }
  }
  return result;
}