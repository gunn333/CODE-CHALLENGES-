//! Counting Bits (LeetCode 338)

// Question Link:
// https://leetcode.com/problems/counting-bits/

#include <bits/stdc++.h>
using namespace std;

vector<int> countBits(int n) {
  vector<int> v;
  v.push_back(0);
  if (n == 0)
    return v;
  v.push_back(1);
  if (n == 1)
    return v;
  v.push_back(1);
  if (n == 2)
    return v;
  for (int i = 3; i <= n; i++) {
    v.push_back(i % 2 + v[i / 2]);
  }
  return v;
}

int main() {
  int n;
  cin >> n;
  vector<int> v = countBits(n);
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  return 0;
}