//! Rearrange array Elements by sign (LeetCode 2149)

// Question Link:
// https://leetcode.com/problems/rearrange-array-elements-by-sign/?envType=daily-question&envId=2024-02-15

#include <bits/stdc++.h>
using namespace std;
vector<int> rearrangeArray(vector<int> &nums) {
  vector<int> pos;
  vector<int> neg;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] >= 0) {
      pos.push_back(nums[i]);
    } else {
      neg.push_back(nums[i]);
    }
  }
  int iPos = 0, iNeg = 0, iArr = 0; // Indexes
  while (iPos < pos.size() &&
         iNeg < neg.size()) { // Check if both indexes are in vector range
    nums[iArr] = pos[iPos];   // Insert positive number
    iArr++;
    iPos++;
    nums[iArr] = neg[iNeg];
    iArr++;
    iNeg++;
  }
  while (iPos < pos.size()) { // If negative vector is finished
    nums[iArr++] = pos[iPos++];
  }
  while (iNeg < neg.size()) {
    nums[iArr++] = neg[iNeg++];
  }
  return nums;
}

int main() {
  vector<int> nums = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
  vector<int> result = rearrangeArray(nums);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  return 0;
}