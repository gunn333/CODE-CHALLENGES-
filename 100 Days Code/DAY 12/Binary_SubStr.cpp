//! Binary SubString

// Question Link:
// https://www.geeksforgeeks.org/problems/binary-string-1587115620/1?page=1&difficulty%5B%5D=-1&category%5B%5D=Strings&sortBy=submissions

#include <iostream>
#include <string>
#include <vector>
using namespace std;
long binarySubstring(int n, string a) {
  int count = 0;
  int total = 0;
  for (int i = 0; i < a.length(); i++) {
    if (a[i] == '1') {
      total = total + count;
      count++;
    }
  }
  return total;
}
int main() {
  string str;
  cin >> str;
  cout << binarySubstring(str.length(), str);
  return 0;
}