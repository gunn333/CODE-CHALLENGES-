//! Largest Positive Integer that exits with a negative number (Leetcode 2441)

// Question Link :
// https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/?envType=daily-question&envId=2024-05-02

#include <bits/stdc++.h>
using namespace std;

int findMaxK(vector<int> &nums) {
  vector<int> pos;
  vector<int> neg;
  int max = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] < 0) {
      neg.push_back(nums[i]);
    } else {
      pos.push_back(nums[i]);
    }
  }
  sort(pos.begin(), pos.end());
  sort(neg.begin(), neg.end());
  for (int j = pos.size() - 1; j >= 0; j--) {
    int key = pos[j] * (-1);
    if (std::find(neg.begin(), neg.end(), key) != neg.end()) {
      max = pos[j];
      break;
    }
  }
  if (max == 0) {
    return -1;
  } else {
    return max;
  }
}

int main() {
  vector<int> nums = {1, 2, 3, 4, 5, -5, -4, -3, -2, -1};
  cout << findMaxK(nums) << endl;
  return 0;
}