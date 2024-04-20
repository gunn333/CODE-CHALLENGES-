//! Find all groups of farmland (Leetcode 1992)

// Question Link:
// https://leetcode.com/problems/find-all-groups-of-farmland/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findFarmland(vector<vector<int>> &land) {
  int n = land.size(), m = land[0].size();
  // res will store the result
  vector<vector<int>> res;
  // visited will store the visited cells
  vector<vector<bool>> visited(n, vector<bool>(m, false));

  // Traverse the matrix
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      // If the cell is not visited and it is a farmland (1)
      if (visited[i][j] == false && land[i][j] == 1) {
        // create a vector to store the coordinates of the farmland
        vector<int> temp = {i, j};
        // i is the starting row and j is the starting column
        temp.push_back(i);
        temp.push_back(j);
        // Apply DFS whenever we find a farmland
        dfs(land, visited, i, j, temp);
        // Push the coordinates of the farmland to the result
        res.push_back(temp);
      }
    }
  }
  return res;
}

void dfs(vector<vector<int>> &land, vector<vector<bool>> &visited, int i, int j,
         vector<int> &temp) {
  // If the cell is out of bounds or it is not a farmland
  if (i < 0 || i >= land.size() || j < 0 || j >= land[0].size() ||
      land[i][j] == 0 || visited[i][j] == true) {
    return;
  }
  // Mark the cell as visited
  visited[i][j] = true;
  // Update the coordinates of the farmland
  temp[2] = max(temp[2], i);
  temp[3] = max(temp[3], j);
  // Apply DFS in all four directions
  dfs(land, visited, i + 1, j, temp);
  dfs(land, visited, i - 1, j, temp);
  dfs(land, visited, i, j + 1, temp);
  dfs(land, visited, i, j - 1, temp);
}

int main() {
  vector<vector<int>> land = {{1, 0, 0}, {0, 1, 1}, {0, 1, 1}};
  vector<vector<int>> res = findFarmland(land);
  for (auto x : res) {
    for (auto y : x) {
      cout << y << " ";
    }
    cout << endl;
  }
  return 0;
}