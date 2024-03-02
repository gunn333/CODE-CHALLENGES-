//! Predict the Winner (leetcode 486)

// Question Link:
// https://leetcode.com/problems/predict-the-winner/

#include <bits/stdc++.h>
using namespace std;

bool predictTheWinner(vector<int> &nums) {
  int n = nums.size();
  // ek vector banaya hai jo ki nums vector ka copy hai
  vector<int> vec(nums);
  for (int len = 2; len <= n; ++len) {
    for (int i = 0; i <= n - len; ++i) {
      int j = i + len - 1;
      vec[i] = max(nums[i] - vec[i + 1], nums[j] - vec[i]);
    }
  }
  return vec[0] >= 0;
}

int main() {
  vector<int> nums = {1, 5, 2};
  cout << predictTheWinner(nums);
  return 0;
}