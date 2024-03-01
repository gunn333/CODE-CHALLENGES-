//! Maximum Odd Binary Number (Leetcode 2864)

// Question Link:
// https://leetcode.com/problems/maximum-odd-binary-number/description/?envType=daily-question&envId=2024-03-01

#include <bits/stdc++.h>
using namespace std;

string maximumOddBinaryNumber(string s) {
  int n = s.size();
  int ones = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      ones++;
    }
  }
  string ans;
  vector<char> result(n, '0');
  result[n - 1] = '1';
  ones--;
  int i = 0;
  while (ones) {
    result[i] = '1';
    i++;
    ones--;
  }
  for (int i = 0; i < n; i++) {
    ans.push_back(result[i]);
  }
  return ans;
}

int main() {
  string s;
  cin >> s;
  cout << maximumOddBinaryNumber(s) << endl;
  return 0;
}