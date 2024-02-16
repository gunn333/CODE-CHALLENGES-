//! Set Mismatch (LeetCode 645)

// Question link:
// https://leetcode.com/problems/set-mismatch/

#include <bits/stdc++.h>
using namespace std;

vector<int> findErrorNums(vector<int> &nums) {
  vector<bool> res(nums.size(), true);
  vector<int> ans;
  set<int> s;
  sort(nums.begin(), nums.end());

  for (int j = 0; j < (nums.size() - 1); j++) {
    if (nums[j] == nums[j + 1]) {
      ans.push_back(nums[j]);
    }
  }
  for (int i = 0; i < nums.size(); i++) {
    res[nums[i] - 1] = false;
  }
  for (int k = 0; k < nums.size(); k++) {
    if (res[k] == true) {
      ans.push_back(k + 1);
    }
  }
  return ans;
}

int main() {
  vector<int> nums = {1, 2, 2, 4};
  vector<int> ans = findErrorNums(nums);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  return 0;
}