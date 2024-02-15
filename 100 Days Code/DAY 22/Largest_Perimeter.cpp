//! Largest Perimeter (LeetCode 2971)

// Question Link:
// https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/?envType=daily-question&envId=2024-02-15

#include <bits/stdc++.h>
using namespace std;

int largestPerimeter(vector<int> &nums) {
  sort(nums.begin(), nums.end());
  long long sum = 0;
  for (int i = 0; i < nums.size(); i++) {
    sum += nums[i];
  }
  for (int i = nums.size() - 1; i >= 0; i--) {
    if (sum - nums[i] > nums[i]) {
      return sum;
    }
    sum = sum - nums[i];
  }
  return -1;
}

int main() {
  vector<int> nums = {2, 1, 2};
  cout << largestPerimeter(nums);
  return 0;
}