//! Triangular Sum of Array (Leetcode 2221)

// Question Link:
// https://leetcode.com/problems/find-triangular-sum-of-an-array/description/

#include <bits/stdc++.h>
using namespace std;

int triangularSum(vector<int> &nums) {
  // Base case
  if (nums.size() == 1) {
    return nums[0];
  }
  // Loop until the size of the vector is 1
  while (nums.size() != 1) {
    for (int i = 1; i < nums.size(); i++) {
      // nums[i-1] prev element mein purane element aur current element ka sum
      // kr diya
      nums[i - 1] = (nums[i - 1] + nums[i]) % 10;
    }
    // then us element ko pop kr diya
    nums.pop_back();
  }
  // return the only element left in the vector (Triangular sum)
  return nums[0];
}

int main() {
  vector<int> nums = {1, 2, 3, 4, 5};
  cout << triangularSum(nums) << endl;
  return 0;
}

/*
nums[i - 1]: Refers to the number on the left side of the current pair.
(nums[i - 1] + nums[i]): Adds the number on the left side of the current pair to
the number on the right side of the current pair. % 10: Keeps only the last
digit of the sum. nums[i - 1] = ..: Updates the number on the left side of the
current pair with the last digit of the sum.
*/