//! Subarray Product Less Than K (Leetcode 713)

// Question Link:
// https://leetcode.com/problems/subarray-product-less-than-k/

#include <bits/stdc++.h>
using namespace std;

int numSubarrayProductLessThanK(vector<int> &nums, int k) {

  // There is no product possible which is less than 1 or 0
  // cause the given 1<= nums[i] <= 999
  if (k <= 1)
    return 0;

  int n = nums.size();

  // cumulative product of subarray
  int product = 1;

  // valid product count
  int count = 0;

  // valid left pointer
  int left = 0;

  // right iterator pointer
  int right = 0;
  for (right = 0; right < n; right++) {
    // get cumulative product
    product *= nums[right];

    // loop till product < k to find valid subarray range
    // subarray range holds the valid num of subarrays whos product < k
    while (product >= k)
      product /= nums[left++];

    // count valid product subarray
    count += right - left + 1;
  }

  return count;
}

int main() {
  vector<int> nums = {10, 5, 2, 6};
  int k = 100;
  cout << numSubarrayProductLessThanK(nums, k) << endl;
  return 0;
}