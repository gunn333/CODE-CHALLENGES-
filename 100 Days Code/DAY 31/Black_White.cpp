//! Seperate black and white Balls (LeetCode 2938)

// Question Link:
// https://leetcode.com/problems/separate-black-and-white-balls/description/

#include <bits/stdc++.h>
using namespace std;

long long minimumSteps(string s) {
  long long ans = 0;
  int left = 0;
  int right = s.size() - 1;
  while (left < right) {
    if (s[left] == '1' && s[right] == '0') {
      ans = ans + right - left;
      left++;
      right--;
    }
    if (s[left] == '0') {
      left++;
    }
    if (s[right] == '1') {
      right--;
    }
  }
  return ans;
}

int main() {
  string s = "100110";
  cout << minimumSteps(s) << endl;
  return 0;
}