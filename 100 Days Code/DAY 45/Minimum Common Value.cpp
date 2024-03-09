//! Minimum Common Value (LeetCode 2540)

// Question Link:
// https://leetcode.com/problems/minimum-common-value

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int getCommon(vector<int> &nums1, vector<int> &nums2) {
  for (int i = 0, j = 0; i < nums1.size() && j < nums2.size();) {
    if (nums1[i] == nums2[j])
      return nums1[i];
    else if (nums1[i] < nums2[j])
      i++;
    else
      j++;
  }
  return -1;
}

int main() {
  vector<int> nums1 = {1, 2, 3, 4, 5};
  vector<int> nums2 = {3, 4, 5, 6, 7};

  cout << getCommon(nums1, nums2);

  return 0;
}