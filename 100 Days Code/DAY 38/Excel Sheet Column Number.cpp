//! Excel Sheet Column Number (LeetCode 171)

// Question Link:
// https://leetcode.com/problems/excel-sheet-column-number/

#include <bits/stdc++.h>
using namespace std;

int titleToNumber(string columnTitle) {
  // sum mein column number store karenge
  int sum = 0;
  // l -> length of columnTitle
  int l = columnTitle.size() - 1;
  // count -> position of character in columnTitle
  int count = 0;
  for (int i = l; i >= 0; i--) {
    // (int)columnTitle[i] -> ASCII value milegi har character ki
    // aur -64 because A ki value 1 hai and its ASCII value is 65 so 65-64 = 1
    // so k ke andar character ki numeric value store ho jayegi
    int k = (int)columnTitle[i] - 64;
    // pow(26, count) -> ismein positional value store karenge
    sum += pow(26, count) * k;
    count++;
  }
  return sum;
}

int main() {
  string columnTitle = "AB";
  cout << titleToNumber(columnTitle);
  return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
/*
Approach i used:
- I used the concept of base 26 number system.
*/