//! Pascal's Triangle Part 2 (Leetcode 119)

// Question Link:
// https://leetcode.com/problems/pascals-triangle-ii/

#include <iostream>
#include <vector>
using namespace std;

vector<int> getRow(int rowIndex) {
  vector<int> pascal;
  pascal.push_back(1);
  for (int i = 1; i <= rowIndex; i++) {
    for (int j = i; j >= 1; j--) {
      if (j == i) {
        pascal.push_back(1);
      } else {
        pascal[j] = pascal[j - 1] + pascal[j];
      }
    }
  }
  return pascal;
}

int main() {
  int n;
  cin >> n;
  vector<int> ans = getRow(n);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
