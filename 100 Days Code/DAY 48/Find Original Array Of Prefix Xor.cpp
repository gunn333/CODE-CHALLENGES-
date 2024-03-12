//! Find The Original Array Of Prefix Xor (LeeCode 2433)

// Question Link:
// https://leetcode.com/problems/find-the-original-array-of-prefix-xor/

#include <iostream>
#include <vector>

using namespace std;

vector<int> findArray(vector<int> &prefix) {
  vector<int> res;
  int n = prefix.size();
  res.push_back(prefix[0]);
  for (int i = 1; i < n; i++) {
    res.push_back(prefix[i - 1] ^ prefix[i]);
  }
  return res;
}

int main() {
  vector<int> prefix = {3, 2, 1, 0};
  vector<int> res = findArray(prefix);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  return 0;
}