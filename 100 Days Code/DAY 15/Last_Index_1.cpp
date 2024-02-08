//! Last Index of 1 (GFG)

// Question Link:
// https://www.geeksforgeeks.org/problems/last-index-of-15847/1?page=1&difficulty%5B%5D=-1&category%5B%5D=Searching&sortBy=submissions

#include <iostream>
using namespace std;
int lastIndex(string s) {
  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] == '1') {
      return i;
    }
  }
  return -1;
}
int main() {
  string s;
  cin >> s;
  cout << lastIndex(s);
  return 0;
}