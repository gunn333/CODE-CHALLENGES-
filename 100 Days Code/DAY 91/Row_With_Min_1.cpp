//! Row with minimum number of 1's (GeeeksforGeeks)

// Question Link:
// https://www.geeksforgeeks.org/problems/row-with-minimum-number-of-1s5430/1

#include <bits/stdc++.h>
using namespace std;

int minRow(int n, int m, vector<vector<int>> &a) {
  int minRow = -1;
  int minOnes = INT_MAX;
  for (int i = 0; i < n; i++) {
    int ones = count(a[i].begin(), a[i].end(), 1);
    if (ones < minOnes) {
      minOnes = ones;
      minRow = i;
    } else if (ones == minOnes) {
      minRow = min(minRow, i);
    }
  }
  return minRow + 1;
}

int main() {
  int n = 4, m = 4;
  vector<vector<int>> a = {
      {0, 1, 1, 1}, {0, 0, 1, 1}, {1, 1, 1, 1}, {0, 0, 0, 0}};
  cout << minRow(n, m, a) << endl;
  return 0;
}