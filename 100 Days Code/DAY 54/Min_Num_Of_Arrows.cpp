//! Minimum Number Of Arrows To Burst Balloons (LeetCode 452)

// Question Link:
// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

#include <bits/stdc++.h>
using namespace std;

int findMinArrowShots(vector<vector<int>> &points) {
  sort(points.begin(), points.end());
  // temporary vector to update every time if there is intersection.
  // intersection in simple words is when the current point is in the range of
  // the previous point
  vector<vector<int>> v;

  // ans to store unique points if no intersection
  int ans = 0;

  // push first point in vector v
  v.push_back(points[0]);

  for (int i = 1; i < points.size(); i++) {
    // points[i][0] is the start of the current point
    // v[0][1] is the end of the previous point
    // points[i][0] <= v[0][1] means there is an intersection between current
    // point and previous point
    if (points[i][0] <= v[0][1]) { // if intersection
      // here i have updated the start and end of the intersection point
      v[0][0] = max(points[i][0], v[0][0]);
      v[0][1] = min(points[i][1], v[0][1]);
    } else {                  // if no intersection
      ans++;                  // increase ans because it is unique count
      v.pop_back();           // pop from v because it is unique point
      v.push_back(points[i]); // push current point in v
    }
  }
  // last unique point
  ans++;
  // all elements in ans will have no intesection
  return ans;
}