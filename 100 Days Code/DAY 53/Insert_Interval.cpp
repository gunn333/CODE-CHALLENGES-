//! Insert Interval (Leetcode 57)

// Question Link:
// https://leetcode.com/problems/insert-interval/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>> &intervals,
                           vector<int> &newInterval) {
  vector<vector<int>> result;
  // inserted is used to check if the newInterval is inserted or not
  bool inserted = false;

  // if the intervals is empty then we can directly push the newInterval
  if (intervals.size() == 0) {
    result.push_back(newInterval);
    return result;
  }

  for (int i = 0; i < intervals.size(); i++) {
    if (!inserted) {
      // newInterval[0] > intervals[i][1] ka matlab hai ki newInterval ka start
      // interval ke end se bada hai
      if (newInterval[0] > intervals[i][1]) {
        result.push_back(intervals[i]);
      } else if (newInterval[1] < intervals[i][0]) {
        result.push_back(newInterval);
        result.push_back({intervals[i]});
        inserted = true;
      } else {
        int start = min(newInterval[0], intervals[i][0]);
        int end = max(newInterval[1], intervals[i][1]);
        result.push_back({start, end});
        inserted = true;
      }
    } else {
      if (result[result.size() - 1][1] >= intervals[i][0]) {
        result[result.size() - 1][1] =
            max(result[result.size() - 1][1], intervals[i][1]);
      } else {
        result.push_back(intervals[i]);
      }
    }
  }
  if (!inserted) {
    result.push_back(newInterval);
    inserted = true;
  }
  return result;
}

int main() {
  vector<vector<int>> intervals = {{1, 3}, {6, 9}};
  vector<int> newInterval = {2, 5};
  vector<vector<int>> result = insert(intervals, newInterval);
  for (auto i : result) {
    cout << i[0] << " " << i[1] << endl;
  }
  return 0;
}
