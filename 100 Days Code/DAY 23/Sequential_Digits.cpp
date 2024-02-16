//! Sequential Digits (LeetCode 1291)

// Question link:
// https://leetcode.com/problems/sequential-digits/

#include <bits/stdc++.h>
using namespace std;

vector<int> sequentialDigits(int low, int high) {
  vector<int> v;
  for (int i = 1; i <= 9; i++) {
    int n = i;
    while (n <= high) {

      if (n >= low) {
        v.push_back(n);
      }
      if ((n + 1) % 10 > n % 10) {
        n = n * 10 + n % 10 + 1;
      } else
        break;
    }
  }
  sort(v.begin(), v.end());
  return v;
}

int main() {
  int low, high;
  cin >> low >> high;
  vector<int> v = sequentialDigits(low, high);
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  return 0;
}