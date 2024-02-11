//! Jump Game II (Leetcode 45) 

// Question Link:
// https://leetcode.com/problems/jump-game-ii/

#include <bits/stdc++.h>
using namespace std;
int jump(vector<int> &nums) {
  int n = nums.size();
  if (n == 1)
    return 0;

  if (nums[0] == 0)
    return -1;

  int left = 0, right = 0, farthest = 0, jump = 0;
  while (right < n - 1) {
    // Checking whats the farthest index we can reach from the current
    // window
    for (int i = left; i <= right; i++) {
      farthest = max(farthest, i + nums[i]);
    }

    // left of new window will be the immediate right of previous window
    left = right + 1;

    // right of new wndow will be the farthest index we can reach from
    // the previous window
    right = farthest;

    // Incrementing the count of jumps for each window
    jump++;
  }
  return jump;
}

int main() {
  vector<int> nums = {2, 3, 1, 1, 4};
  cout << jump(nums) << endl;
  return 0;
}