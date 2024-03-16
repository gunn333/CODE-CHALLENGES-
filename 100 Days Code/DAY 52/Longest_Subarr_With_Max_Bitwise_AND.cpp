//! Maximum Subarray with maximum bitwise AND (LeetCode 2419)

// Question Link:
// https://leetcode.com/problems/maximum-subarray-with-maximum-bitwise-and/

#include <bits/stdc++.h>
using namespace std;

int longestSubarray(std::vector<int> &nums) {
  unsigned int max = 0;
  unsigned int maxCount = 0;
  unsigned int count = 0;

  for (unsigned int i = 0; i < nums.size(); i++) {
    if (nums[i] == max) {
      count++;
    } else if (nums[i] > max) {
      max = nums[i];
      count = 1;
      maxCount = 0;
    } else {
      count = 0;
    }

    if (count > maxCount) {
      maxCount = count;
    }
  }
  return maxCount;
}

int main() {
  vector<int> nums = {1, 2, 4, 8, 16, 32, 64, 128};
  cout << longestSubarray(nums);
  return 0;
}
