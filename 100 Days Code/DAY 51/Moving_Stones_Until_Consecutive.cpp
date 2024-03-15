//! Moving Stones Until Consecutive (LeetCode 1033)

// Question Link:
// https://leetcode.com/problems/moving-stones-until-consecutive/

#include <bits/stdc++.h>
using namespace std;

vector<int> numMovesStones(int a, int b, int c) {
  // nums -> stores the three stones : a, b, c
  vector<int> nums{a, b, c};
  sort(nums.begin(), nums.end());
  if (nums[2] - nums[0] == 2) {
    return {0, 0};
  } else {
    int first, last;
    first = nums[1] - nums[0] - 1;
    last = nums[2] - nums[1] - 1;
    vector<int> arr(2);
    if (first < 2 || last < 2) {
      arr[0] = 1;
    } else {
      arr[0] = 2;
    }
    arr[1] = first + last;
    return arr;
  }
}

int main() {
  int a = 1, b = 2, c = 5;
  vector<int> result = numMovesStones(a, b, c);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  return 0;
}