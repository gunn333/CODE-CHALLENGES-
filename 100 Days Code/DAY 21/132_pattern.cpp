//! 132 pattern (Leetcode 456)

// Question Link:
// https://leetcode.com/problems/132-pattern/

#include <bits/stdc++.h>
using namespace std;
bool find132pattern(vector<int> &nums) {
  int n = nums.size();
  if (n <= 2) {
    return false;
  }
  int first = nums[0];
  for (int j = 1; j < n - 1; j++) {
    if (nums[j] > first) {
      int k = j + 1;
      while (k < n && first >= nums[k]) {
        k++;
      }
      if (k != n && nums[k] < nums[j])
        return true;
    }
    first = min(nums[j], first);
  }
  return false;
}

int main() {
  vector<int> nums = {1, 2, 3, 4};
  cout << find132pattern(nums);
  return 0;
}
