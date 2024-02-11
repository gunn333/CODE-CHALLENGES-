//! Smallest Divisor given a threshold (LeetCode 1283)

// Question Link:
// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

#include <bits/stdc++.h>
using namespace std;

int getMax(vector<int> &nums) {
  int max = nums[0];
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] > max)
      max = nums[i];
  }
  return max;
}

int divide(vector<int> &nums, int divisor) {
  int sum = 0;
  for (int i = 0; i < nums.size(); i++) {
    sum += ceil(double(nums[i]) / double(divisor));
  }
  return sum;
}

int smallestDivisor(vector<int> &nums, int threshold) {
  int low = 1;
  int high = getMax(nums);
  int res = 0;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (divide(nums, mid) <= threshold) {
      res = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return res;
}

int main() {
  vector<int> nums = {1, 2, 5, 9};
  int threshold = 6;
  cout << smallestDivisor(nums, threshold) << endl;
  return 0;
}