//! Excel Sheet Column Title (LeetCode - 168)

// Question Link:
// https://leetcode.com/problems/excel-sheet-column-title/

#include <iostream>
#include <string>
#include <vector>

using namespace std;
#include <algorithm>

string convertToTitle(int columnNumber) {
  string result = "";
  while (columnNumber > 0) {
    columnNumber--;
    int curr_ele = columnNumber % 26;
    columnNumber /= 26;
    result.push_back(curr_ele + 'A');
  }
  reverse(result.begin(), result.end());
  return result;
}

int main() {
  int columnNumber;
  cin >> columnNumber;
  cout << convertToTitle(columnNumber);
  return 0;
}