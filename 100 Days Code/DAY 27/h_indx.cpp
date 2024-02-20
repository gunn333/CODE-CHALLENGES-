//! H-Index (LeetCode 274)

// Question Link:
// https://leetcode.com/problems/h-index/

#include <bits/stdc++.h>
using namespace std;

int hIndex(vector<int> &citations) {
  sort(citations.begin(), citations.end());
  int count = 0;
  int prev;
  for (int i = citations.size() - 1; i >= 0; i--) {
    if (citations.at(i) < count) {
      break;
    }
    count++;
    prev = citations.at(i);
  }
  return min(prev, count);
}

int main() {
  vector<int> citations = {3, 0, 6, 1, 5};
  cout << hIndex(citations) << endl;
  return 0;
}