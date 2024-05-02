//! Guess Number Higher or Lower (LeetCode 374)

// Question Link :
// https://leetcode.com/problems/guess-number-higher-or-lower/

#include <bits/stdc++.h>
using namespace std;

int guess(int num);

int guessNumber(int n) {
  // Initialize the left and right pointers
  int left = 1, right = n;
  // Binary search
  while (left <= right) {
    // Calculate the mid
    int mid = left + (right - left) / 2;
    // If the guessed number is correct
    if (guess(mid) == 0) {
      return mid;
    }
    // If the guessed number is higher
    else if (guess(mid) == 1) {
      left = mid + 1;
    }
    // If the guessed number is lower
    else {
      right = mid - 1;
    }
  }
  return -1;
}

int main() {
  // Test case 1
  int n = 10;
  cout << guessNumber(n) << endl;
  // Test case 2
  n = 1;
  cout << guessNumber(n) << endl;
  // Test case 3
  n = 2;
  cout << guessNumber(n) << endl;
  return 0;
}