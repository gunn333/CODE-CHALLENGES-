//! Binary Subarrays With Sum (LeetCode 930)

// Question Link:
// https://leetcode.com/problems/binary-subarrays-with-sum/

#include <bits/stdc++.h>

using namespace std;

int numSubarraysWithSum(vector<int> &nums, int goal) {
  int count = 0;
  int ones = 0;
  int zeros_arr[nums.size() + 1];
  zeros_arr[0] = 0;
  for (int i = 0; i < nums.size(); i++) {
    zeros_arr[ones]++;
    if (nums[i]) {
      ones++;
      zeros_arr[ones] = 0;
    }

    if (ones >= goal)
      count += (zeros_arr[ones - goal]);
  }
  return count;
}

int main() {
  vector<int> nums = {1, 0, 1, 0, 1};
  int goal = 2;
  cout << numSubarraysWithSum(nums, goal) << endl;
  return 0;
}

/*
Logic I used:

1. Summary: I used a prefix sum array to store the number of zeros before the
   current index. Then I used a sliding window to count the number of subarrays
   with the sum equal to the goal.

Counting the zeros before each one

Sliding windows - Adding the number of zeros
+ 1 for current - goal 0 is special case we do not add 1 for the first 1 o's + 1
count for 0,0,0,1 will be 4 and will be in position 0, before counting the 1 for
goal == 0 it will be without the +1
*/