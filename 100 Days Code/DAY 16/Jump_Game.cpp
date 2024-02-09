//! Jump Game (LeetCode - 55)

// Question Link:
// https://leetcode.com/problems/jump-game/

#include <bits/stdc++.h>
using namespace std;
bool canJump(vector<int> &nums) {
  int steps = 0;
  int size = nums.size();

  for (int i = 0; i < size; i++) {
    if (steps < 0)
      return false;

    steps = max(steps, nums[i]) - 1;
    /*
    max(steps, nums[i]) isse hum maximum steps from current position
    nikalenge and -1 By subtracting 1, we accurately repstepsent the number of
    steps needed to move to the next position. So, with nums[i] = 3,
    subtracting 1 gives us 2, which correctly indicates that we can move 2
    steps forward from position i, using one step to move to the next
    position and having 2 steps remaining.
    In crisp, we are decrementing the steps by 1, as we are moving to the
    next position
    */
  }
  return true;
}
int main() {
  vector<int> nums = {2, 3, 1, 1, 4};
  cout << canJump(nums) << endl;
  return 0;
}

/*
int n = nums.size();
        if(n == 1){
            return true;
        }
        if(nums[0] == 0){
            return false;
        }
        int steps = 0;
        for(int i = 0; i<n ; i++){
            if(steps < i){
                return false;
            }
              i+nums[i] is the maximum index that can be reached from i
            steps = max(steps, i + nums[i]);
        }
        return true;

*/