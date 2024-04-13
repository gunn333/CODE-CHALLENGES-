//! Maximal Rectangle (Leetcode 85)

// Question Link:
// https://leetcode.com/problems/maximal-rectangle/

#include <bits/stdc++.h>
using namespace std;

int maximalRectangle(vector<vector<char>> &matrix) {
  if (matrix.empty())
    return 0;

  // maxArea will store the maximum area of the rectangle
  int maxArea = 0;
  // rows and cols size
  int rows = matrix.size();
  int cols = matrix[0].size();

  // left will store the leftmost index of the rectangle
  // cols, 0 means that we are initializing the vector with 0 of size cols
  // we are initializing it with 0 because we need to calculate the leftmost
  // index of the rectangle
  // left will have the same size as the number of columns because we need to
  // keep track of the leftmost index of the rectangle for each column
  vector<int> left(cols, 0);
  // right will store the rightmost index of the rectangle
  // cols, cols means that we are initializing the vector with cols of size cols
  vector<int> right(cols, cols);
  // Here we are initializing the heights vector with 0 of size cols because we
  // need to calculate the height of the rectangle heights will store the height
  // of the rectangle
  // heights of rectangle is the number of consecutive 1's in the column
  vector<int> heights(cols, 0);

  // We will iterate over the rows and columns of the matrix
  for (int i = 0; i < rows; ++i) {
    // cur_left will store the current leftmost index of the rectangle
    // cur_right will store the current rightmost index of the rectangle
    int cur_left = 0, cur_right = cols;

    // We will iterate over the columns of the matrix
    for (int j = 0; j < cols; ++j) {
      // If the current element is 0 then we will update the heights, left and
      // cur_left
      if (matrix[i][j] == '0') {
        heights[j] = 0;
        left[j] = 0;
        cur_left = j + 1;
      } else {
        heights[j] += 1;
        // We will update the leftmost index of the rectangle for the current
        // column
        left[j] = max(left[j], cur_left);
      }
    }

    // j = cols - 1 because we are iterating from the last column to the first
    // column
    for (int j = cols - 1; j >= 0; --j) {
      // If the current element is 0 then we will update the right and cur_right
      if (matrix[i][j] == '0') {
        // right[j] = cols because we are initializing the rightmost index of
        // the rectangle with cols
        right[j] = cols;
        // cur_right will store the current rightmost index of the rectangle
        cur_right = j;
      } else {
        // We will update the rightmost index of the rectangle for the current
        right[j] = min(right[j], cur_right);
      }
    }

    // We will iterate over the columns of the matrix and calculate the maximum
    // area
    for (int j = 0; j < cols; ++j) {
      // maxArea = max(maxArea, heights[j] * (right[j] - left[j])) will give us
      // the area of the rectangle
      // heights[j] * (right[j] - left[j]) will give us the area of the
      // rectangle
      maxArea = max(maxArea, heights[j] * (right[j] - left[j]));
    }
  }
  return maxArea;
}

int main() {
  vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                 {'1', '0', '1', '1', '1'},
                                 {'1', '1', '1', '1', '1'},
                                 {'1', '0', '0', '1', '0'}};

  cout << maximalRectangle(matrix) << endl;
  return 0;
}