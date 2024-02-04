//! Reverse a string

#include <iostream>
#include <string>
#include <vector>
using namespace std;
string reverseString(string str) {
  vector<char> v;
  int n = str.length() - 1;

  for (int i = n; i >= 0; i--) {
    v.push_back(str[i]);
  }
  for (int i = 0; i <= n; i++) {
    str[i] = v[i];
  }
  return str;
}
int main() {
  string str;
  cin >> str;
  cout << reverseString(str);
  return 0;
}