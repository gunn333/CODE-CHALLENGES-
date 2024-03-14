//! Chalkboard XOR Game (LeetCode 810)

// Question Link:
// https://leetcode.com/problems/chalkboard-xor-game/

#include <bits/stdc++.h>
using namespace std;

bool xorGame(vector<int> &nums) {
  int n = nums.size();
  int xorr = 0;   // we created a variable to store xorof all members of the
                  // vector
  int zeroes = 0; // we created a variable to count zeroes

  for (int i = 0; i < n; i++) {
    xorr ^= nums[i];
    if (nums[i] == 0)
      zeroes++;
  }
  if (zeroes == n) {
    // if all the members of the vector are 0
    return false;
  }
  if (xorr == 0) {
    // if xor of all the members are 0 but number of 0 are !=n
    return true;
  }
  if (n % 2 == 0) {
    // if xor of all element is !=0  and we got even number of
    // elements in the vector
    return true;
  }
  return false; // if xor of all element is !=0  and we got odd number of
                // elements in the vector
}

int main() {
  vector<int> nums = {1, 1, 2};
  cout << xorGame(nums) << endl;
  return 0;
}
