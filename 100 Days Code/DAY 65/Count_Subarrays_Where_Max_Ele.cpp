//! Count Subarrays Where Max Element appears at least K times (Leetcode 2962)

#include <bits/stdc++.h>
using namespace std;

long long countSubarrays(vector<int> &nums, int k) {
  int n = nums.size();
  // Counter for the frequency of the maximum element in the
  // current subarray
  int freq = 0;
  long long res = 0; // Variable to store the result, i.e., the count of
                     // subarrays meeting the condition
  int max_ele = 0; // Variable to store the maximum element in the entire array

  // Find the maximum element in the array
  for (int i = 0; i < n; i++) {
    max_ele = max(max_ele, nums[i]);
  }

  // Main loop with two pointers i and j
  for (int i = 0, j = 0; i < n; i++) {
    // Increment frequency if the current element is equal to max_ele
    if (nums[i] == max_ele)
      freq++;

    // Check if frequency is greater than or equal to k
    if (freq < k)
      continue; // Continue to the next iteration if frequency is less than k
    else {
      // Inner while loop to count subarrays
      while (nums[j] != max_ele && j < n) {
        // Add the count of subarrays (n - i) to the result
        res = res + n - i;
        j++;
      }
      // Add the count of subarrays (n - i) to the result once more
      res = res + n - i;
      j++;
      // Decrement frequency
      freq--;
    }
  }
  // Return the final result
  return res;
}

int main() {
  // Example 1
  vector<int> nums = {1, 2, 1, 2, 3};
  int k = 2;
  cout << countSubarrays(nums, k) << endl; // Output: 7

  // Example 2
  nums = {1, 4, 2, 5, 3};
  k = 2;
  cout << countSubarrays(nums, k) << endl; // Output: 3

  return 0;
}