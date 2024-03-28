//! Length of the longest subarray with most K Frequency (Leetcode 2958)

#include <bits/stdc++.h>
using namespace std;

int maxSubarrayLength(vector<int> &nums, int k) {
  int start = 0, end = 0, ans = 0;
  unordered_map<int, int> map;
  for (int i = 0; i < nums.size(); i++) {
    map[nums[i]]++;
    while (start < i and map[nums[i]] > k) {
      map[nums[start]]--;
      if (map[nums[start]] == 0)
        map.erase(nums[start]);
      start++;
    }
    ans = max(ans, i - start + 1);
  }
  return ans;
}

int main() {
  vector<int> nums = {1, 2, 2, 3, 1, 1, 1, 2, 2, 3};
  int k = 2;
  cout << maxSubarrayLength(nums, k) << endl;
  return 0;
}