//! Count Elements By Frequency (Leetcode 3005)

// Question Link:
// https://leetcode.com/problems/count-elements-by-frequency/

#include <bits/stdc++.h>
using namespace std;

int maxFrequencyElements(vector<int> &nums) {

  int i = 1;
  int count = 1;
  int maxi = 0;
  vector<int> ans;
  sort(nums.begin(), nums.end());
  while (i < nums.size()) {
    if (nums[i] == nums[i - 1]) {
      count++;
    }

    else {
      ans.push_back(count);
      count = 1;
    }
    i++;
  }

  ans.push_back(count);

  sort(ans.rbegin(), ans.rend());
  int sum = ans[0];

  i = 1;
  while (i < ans.size()) {
    if (ans[i] == ans[i - 1]) {
      sum += ans[i];
    } else {
      return sum;
    }
    i++;
  }

  return sum;
}

int main() {
  vector<int> nums = {1, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};
  cout << maxFrequencyElements(nums);
  return 0;
}