//! Product Of Array Except Self (LeetCode 238)

// Question Link:
// https://leetcode.com/problems/product-of-array-except-self/

#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums) {
  int n = nums.size();
  vector<int> output(n, 1);

  int leftProduct = 1;
  for (int i = 0; i < n; ++i) {
    output[i] = leftProduct;
    leftProduct *= nums[i];
  }

  int rightProduct = 1;
  for (int i = n - 1; i >= 0; --i) {
    output[i] *= rightProduct;
    rightProduct *= nums[i];
  }

  return output;
}

int main() {
  vector<int> nums = {1, 2, 3, 4};
  vector<int> result = productExceptSelf(nums);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  return 0;
}