//! Contiguous Array (LeetCode 525)

// Question Link:
// https://leetcode.com/problems/contiguous-array/

#include <bits/stdc++.h>
using namespace std;

int findMaxLength(vector<int> &nums) {
  int n = nums.size();
  unordered_map<int, int> mp;
  for (int i = 0; i < n; i++)
    if (nums[i] == 0)
      nums[i] = -1;

  int sum = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    sum += nums[i];
    if (sum == 0)
      ans = i + 1;
    else if (sum != 0 && mp[sum] == 0)
      mp[sum] = i + 1;
    else
      ans = max(ans, i + 1 - mp[sum]);
  }
  return ans;
}

int main() {
  vector<int> nums = {0, 1, 0};
  cout << findMaxLength(nums);
  return 0;
}

/*
Approach:
We are given an array of 0s and 1s. We have to find the maximum length of a
contiguous subarray with an equal number of 0s and 1s. We can convert all 0s to
-1 and then find the maximum length of a contiguous subarray with a sum of 0. We
will use a map to store the sum and its index. If the sum is 0, then the answer
will be the current index + 1. If the sum is not 0 and the sum is not in the
map, then we will store the sum and its index in the map. If the sum is already
in the map, then we will update the answer with the maximum of the current
answer and the difference between the current index and the index of the sum in
the map. We will return the answer at the end.
*/