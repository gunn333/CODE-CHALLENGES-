//! Sort Array By Parity (LeetCode 905)

// Question Link:
// https://leetcode.com/problems/sort-array-by-parity/

#include <iostream>
#include <vector>
using namespace std;
vector<int> sortArrayByParity(vector<int> &nums) {
  vector<int> result;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] % 2 == 0) {
      result.push_back(nums[i]);
    }
  }
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] % 2 != 0) {
      result.push_back(nums[i]);
    }
  }
  return result;
}
int main() {
  vector<int> nums = {3, 1, 2, 4};
  vector<int> result = sortArrayByParity(nums);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  return 0;
}