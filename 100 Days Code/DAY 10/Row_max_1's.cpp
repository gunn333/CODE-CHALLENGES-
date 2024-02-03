//! Given a boolean 2D array of n x m dimensions, consisting of only 1's and
//! 0's, where each row is sorted. Find the 0-based index of the first row that
//! has the maximum number of 1's.

#include <bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int>> arr, int n, int m) {
  int max_count = INT_MIN;
  int index = 0;
  for (int i = 0; i < n; i++) {
    int count = 0;
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == 1) {
        count++;
      }
      if (count > max_count) {
        max_count = std::max(max_count, count);
        index = i;
      }
    }
  }
  if (max_count == 0) {
    return -1;
  }
  return index;
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
  cout << rowWithMax1s(arr, n, m) << endl;
  return 0;
}