//! Exit Point of a Matrix (GeeeksforGeeks)

// Question Link :
// https://www.geeksforgeeks.org/problems/exit-point-in-a-matrix0905/1

#include <bits/stdc++.h>
using namespace std;

vector<int> FindExitPoint(int n, int m, vector<vector<int>> &mat) {
  vector<int> ans = {-1, -1};
  int i = 0, j = 0;
  char dir = 'R';

  while (i < n && i >= 0 && j < m && j >= 0) {
    ans[0] = i;
    ans[1] = j;
    if (mat[i][j] == 1) {
      mat[i][j] = 0;
      if (dir == 'R') {
        dir = 'D'; // down
        i++;
      } else if (dir == 'D') {
        dir = 'L'; // left
        j--;
      } else if (dir == 'L') {
        dir = 'U'; // up
        i--;
      } else {
        dir = 'R';
        j++;
      }
    } else {
      if (dir == 'R')
        j++;
      else if (dir == 'D')
        i++;
      else if (dir == 'L')
        j--;
      else
        i--;
    }
  }
  return ans;
}

int main() {
  // Test case 1
  int n = 4, m = 4;
  vector<vector<int>> mat = {
      {0, 0, 1, 0}, {1, 0, 0, 0}, {0, 0, 0, 0}, {1, 0, 1, 0}};
  vector<int> ans = FindExitPoint(n, m, mat);
  cout << ans[0] << " " << ans[1] << endl;
  // Test case 2
  n = 3, m = 3;
  mat = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  ans = FindExitPoint(n, m, mat);
  cout << ans[0] << " " << ans[1] << endl;
  return 0;
}