//! Find All Duplicates in an Array (Leetcode 442)

// Question Link:
// https://leetcode.com/problems/find-all-duplicates-in-an-array/

#include <bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(vector<int> &nums) {
  vector<int> ans;
  sort(nums.begin(), nums.end());
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] == nums[i - 1]) {
      ans.push_back(nums[i]);
    }
  }
  return ans;
}

int main() {
  vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
  vector<int> result = findDuplicates(nums);
  for (int i : result) {
    cout << i << " ";
  }
  return 0;
}