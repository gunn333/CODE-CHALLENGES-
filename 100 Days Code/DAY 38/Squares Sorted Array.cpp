//! Squares of a Sorted Array (Leetcode 977)

// Question Link:
// https://leetcode.com/problems/squares-of-a-sorted-array/

#include <bits/stdc++.h>
using namespace std;

vector<int> sortedSquares(vector<int> &nums) {
  int n = nums.size();
  vector<int> result;
  for (int i = 0; i < n; i++) {
    int curr = nums[i];
    result.push_back(pow(curr, 2));
  }
  sort(result.begin(), result.end());
  return result;
}

int main() {
  vector<int> nums = {-4, -1, 0, 3, 10};
  vector<int> result = sortedSquares(nums);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  return 0;
}