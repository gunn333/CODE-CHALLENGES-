//! Remove K digits from the number so that the new number is the smallest
//! possible. (Leetcode - 402)

// Question Link:
// https://leetcode.com/problems/remove-k-digits/

#include <bits/stdc++.h>
using namespace std;
string removeKdigits(string num, int k) {
  int len = num.length();
  if (len <= k) {
    return "0";
  }
  vector<char> result;

  for (int i = 0; i < len; i++) {
    while (!result.empty() && num[i] < result.back() && k > 0) {
      result.pop_back();
      k--;
    }
    result.push_back(num[i]);
  }

  while (k > 0) {
    result.pop_back();
    k--;
  }

  // Remove leading zeros
  int i = 0;
  while (i < result.size() && result[i] == '0') {
    i++;
  }

  // Form the final result
  return (i == result.size()) ? "0" : string(result.begin() + i, result.end());
}

int main() {
  string num;
  int k;
  cin >> num >> k;
  cout << removeKdigits(num, k);
  return 0;
}