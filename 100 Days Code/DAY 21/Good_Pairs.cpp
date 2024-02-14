//! Number of Good Pairs (LeetCode 1512)

// Question Link:
// https://leetcode.com/problems/number-of-good-pairs/

#include <bits/stdc++.h>
using namespace std;

int numIdenticalPairs(vector<int> &nums) {
  vector<pair<int, int>> res;
  for (int i = 0; i < nums.size() - 1; i++) {
    for (int j = i + 1; j < nums.size(); j++) {
      if (nums[i] == nums[j]) {
        res.push_back(make_pair(i, j));
      }
    }
  }
  return res.size();
}

int main() {
  vector<int> nums = {1, 2, 3, 1, 1, 3};
  cout << numIdenticalPairs(nums);
  return 0;
}