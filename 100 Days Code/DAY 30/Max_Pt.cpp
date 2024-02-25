//! Max Points on a Line (Leetcode 149)

// Question Link:
// https://leetcode.com/problems/max-points-on-a-line/

#include <bits/stdc++.h>
using namespace std;
int maxPoints(vector<vector<int>> &points) {
  int n = points.size();
  //  Edge cases for 0 or 1 points
  if (n <= 1) {
    return 1;
  }
  //   max_pt is the maximum number of points on a line
  int max_pt = 2;
  //   i -> first point, j -> second point and k -> other points
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int total = 2;
      for (int k = 0; k < n; k++) {
        /*
        deltaX1 = x2 - x1, deltaY1 = y2 - y1
        deltaX2 = x3 - x1, deltaY2 = y3 - y1
        x2 -> points[j][0], x1 -> points[i][0], x3 -> points[k][0]
        points[i] = (x1, y1), points[j] = (x2, y2), points[k] = (x3, y3)
        y2 -> points[j][1], y1 -> points[i][1], y3 -> points[k][1]
        */
        int deltaX1 = points[j][0] - points[i][0];
        int deltaY1 = points[j][1] - points[i][1];
        int deltaX2 = points[k][0] - points[i][0];
        int deltaY2 = points[k][1] - points[i][1];
        if (k == i || k == j) {
          continue;
        }
        // If the points are collinear then the slope will be same
        if (deltaY1 * deltaX2 == deltaY2 * deltaX1) {
          total++;
        }
      }
      max_pt = max(max_pt, total);
    }
  }
  return max_pt;
}

int main() {
  vector<vector<int>> points = {{1, 1}, {2, 2}, {3, 3}};
  cout << maxPoints(points) << endl;
  return 0;
}