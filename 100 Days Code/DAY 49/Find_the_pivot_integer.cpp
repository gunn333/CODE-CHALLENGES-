//! Find The Pivot Integer (Leetcode 2485)

// Question Link:
// https://leetcode.com/problems/find-the-pivot-integer

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int pivotInteger(int n) {
  vector<int> prefix, suffix;
  int temp = 0;
  for (int i = 1; i <= n; i++) {
    temp += i;
    prefix.push_back(temp);
  }
  temp = 0;
  for (int i = n; i >= 1; i--) {
    temp += i;
    suffix.push_back(temp);
  }
  reverse(suffix.begin(), suffix.end());
  for (int i = 0; i < prefix.size(); i++) {
    if (prefix[i] == suffix[i]) {
      return i + 1;
    }
  }
  return -1;
}

int main() {
  int n = 8;
  cout << pivotInteger(n);
  return 0;
}