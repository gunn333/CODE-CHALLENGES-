//! K Weakest Rows in a Matrix (Leetcode 1337)

// Question Link:
// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

#include <bits/stdc++.h>
using namespace std;
vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
  int rows = mat.size();
  int cols = mat[0].size();
  vector<pair<int, int>> res;

  for (int i = 0; i < rows; i++) {
    int count = 0;
    for (int j = 0; j < cols; j++) {
      if (mat[i][j] == 1) {
        count++;
      }
    }
    res.push_back(make_pair(count, i));
  }
  vector<int> kweak;
  sort(res.begin(), res.end());
  for (int i = 0; i < k; i++) {
    // The second element of the pair is the index of the row
    kweak.push_back(res[i].second);
  }

  return kweak;
}

int main() {
  vector<vector<int>> mat = {{1, 1, 0, 0, 0},
                             {1, 1, 1, 1, 0},
                             {1, 0, 0, 0, 0},
                             {1, 1, 0, 0, 0},
                             {1, 1, 1, 1, 1}};
  int k = 3;
  vector<int> res = kWeakestRows(mat, k);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  return 0;
}