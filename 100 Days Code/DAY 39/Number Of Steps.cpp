//! Number Of Steps (LeetCode 1342)

// Question Link:
// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/

#include <bits/stdc++.h>
using namespace std;

int numberOfSteps(int num) {
  int steps = 0;

  while (num != 0) {
    if (num % 2 == 0) {
      num = num / 2;
      steps++;
    } else {
      num -= 1;
      steps++;
    }
  }
  return steps;
}

int main() {
  int n;
  cin >> n;
  cout << numberOfSteps(n);
  return 0;
}