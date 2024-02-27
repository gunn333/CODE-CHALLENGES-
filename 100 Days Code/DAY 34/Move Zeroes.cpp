//! Move Zeroes (LeetCode 283)

// Question Link:
// https://leetcode.com/problems/move-zeroes/

#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int> &nums) {
  vector<int> ans;
  int count = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] != 0) {
      ans.push_back(nums[i]);
    } else {
      count++;
    }
  }
  for (int i = 0; i < count; i++) {
    ans.push_back(0);
  }
  nums = ans;
}

int main() {
  vector<int> nums = {0, 1, 0, 3, 12};
  moveZeroes(nums);
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
  }
  return 0;
}