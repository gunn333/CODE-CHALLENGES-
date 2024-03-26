//! First Missing Positive (Leetcode 41)

// Question Link:
// https://leetcode.com/problems/first-missing-positive/

#include <bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int> &nums) {
  int n = nums.size();
  vector<bool> present(n + 1, false);
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] > n + 1) {
      continue;
    }
    if (nums[i] >= 0) {
      present[nums[i]] = true;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (present[i] == false) {
      return i;
    }
  }
  return n + 1;
}

int main() {
  vector<int> nums = {1, 2, 0};
  cout << firstMissingPositive(nums) << endl;
  return 0;
}