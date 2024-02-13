//! Find The Duplicate number in an array  (LeetCode 287)

// Question Link:
// https://leetcode.com/problems/find-the-duplicate-number/submissions/1174203253/?envType=daily-question&envId=2024-02-13

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int findDuplicate(vector<int> &nums) {
  sort(nums.begin(), nums.end());

  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] == nums[i - 1]) {
      return nums[i];
    }
  }
  return -1;
}

int main() {
  vector<int> nums = {1, 3, 4, 2, 2};
  cout << findDuplicate(nums);
  return 0;
}