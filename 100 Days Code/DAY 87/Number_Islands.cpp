//! Number of Islands (LeetCode 200)

// Question Link:
// https://leetcode.com/problems/number-of-islands/

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>> &grid, int i, int j,
         vector<vector<bool>> &visited) {
  // i<0 -> if i is less than 0 means we are out of the grid
  // i>=grid.size() -> if i is greater than or equal to the number of rows in
  // the grid means we are out of the grid
  // j<0 -> if j is less than 0 means we are out of the grid
  // j>=grid[0].size() -> if j is greater than or equal to the number of columns
  // in the grid means we are out of the grid
  // visited[i][j] == true -> if the node is already visited
  // grid[i][j] == '0' -> if the node is water (0)
  if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
      visited[i][j] == true || grid[i][j] == '0')
    return;

  // mark the node as visited
  visited[i][j] = true;
  // Apply dfs on the 4 directions
  // i+1, j -> down
  // i, j+1 -> right
  // i-1, j -> up
  // i, j-1 -> left
  dfs(grid, i + 1, j, visited);
  dfs(grid, i, j + 1, visited);
  dfs(grid, i - 1, j, visited);
  dfs(grid, i, j - 1, visited);
}
int numIslands(vector<vector<char>> &grid) {
  int n = grid.size();
  // if grid is empty
  if (n == 0)
    return 0;
  // m is the number of columns in the grid
  int m = grid[0].size();
  // visited vector to keep track of visited nodes in the grid
  vector<vector<bool>> visited(n, vector<bool>(m, false));

  // count_islands to keep track of the number of islands
  int count_islands = 0;
  // loop through the grid
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      // if the node is not visited and the node is land (1)
      if (visited[i][j] == false && grid[i][j] == '1') {
        // call the dfs function
        dfs(grid, i, j, visited);
        // increment the count_islands of islands
        count_islands++;
      }
    }
  }
  return count_islands;
}

int main() {
  vector<vector<char>> grid = {{'1', '1', '0', '0', '0'},
                               {'1', '1', '0', '0', '0'},
                               {'0', '0', '1', '0', '0'},
                               {'0', '0', '0', '1', '1'}};
  cout << numIslands(grid) << endl;
  return 0;
}