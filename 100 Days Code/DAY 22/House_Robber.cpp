//! House Robber Problem (LeetCode 198)

#include <bits/stdc++.h>
using namespace std;

int rob(vector<int> &nums) {
  if (nums.size() == 1)
    return nums[0];
  // same as fibonacci series
  int prev_prev = nums[0];
  int prev = max(nums[0], nums[1]);
  int res = prev;
  for (int i = 3; i <= nums.size(); i++) {
    res = max(prev, prev_prev + nums[i - 1]);
    prev_prev = prev;
    prev = res;
  }
  return res;
}

int main() {
  vector<int> nums = {1, 2, 3, 1};
  cout << rob(nums);
  return 0;
}