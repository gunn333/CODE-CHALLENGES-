//! Largest Odd Number in String (LeetCode 1903)

// Question Link:
// https://leetcode.com/problems/largest-odd-number-in-string/

#include <bits/stdc++.h>
using namespace std;

string largestOddNumber(string num) {
  for (int i = num.size() - 1; i >= 0; i--) {
    if ((int)num[i] % 2)
      break;
    else
      num.pop_back();
  }
  return num;
}

int main() {
  string num = "35427";
  cout << largestOddNumber(num);
  return 0;
}