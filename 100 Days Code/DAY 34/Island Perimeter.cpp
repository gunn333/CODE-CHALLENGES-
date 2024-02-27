//! Island Perimeter (LeetCode 463)

// Question Link:
// https://leetcode.com/problems/island-perimeter/

#include <bits/stdc++.h>
using namespace std;

int islandPerimeter(vector<vector<int>> &grid) {

  int perimeter = 0;
  int row = grid.size();    // cal row size
  int col = grid[0].size(); // cal col size
  int peri_to_reduce =
      0; // perimeter which is common in both ,we need to reduce that

  for (int i = 0; i < row; i++) {

    for (int j = 0; j < col; j++) {

      if (grid[i][j] == 1) { // iff that cell is water then only find its area

        perimeter += 4; // initially add peri 4 to all the cells

        if ((j + 1 < col) &&
            grid[i][j + 1] ==
                1) { // now , check the right side of the current cell whether
                     // it is filled with water or not , if yes reduce that
                     // peri by 2 as they share the common sides

          peri_to_reduce += 2;
        }

        if ((i + 1 < row) &&
            grid[i + 1][j] ==
                1) { // same reason as above , but now check for bottom of the
                     // current cell for water == 1 , reduce by two

          peri_to_reduce += 2;
        }
      }
    }
  }

  return (perimeter - peri_to_reduce); // return the difference btwn the
                                       // original and the reduced perimeter
}

int main() {
  vector<vector<int>> grid = {
      {0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
  cout << islandPerimeter(grid) << endl;
  return 0;
}