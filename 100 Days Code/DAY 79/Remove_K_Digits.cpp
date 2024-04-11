//! Remove K Digits (LeetCode 402)

// Question Link:
// https://leetcode.com/problems/remove-k-digits/

#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k) {
  int len = num.length();
  //   k is greater than or equal to the length of the number because in that
  //   case, we can remove all the digits
  if (len <= k) {
    return "0";
  }
  vector<char> result;

  for (int i = 0; i < len; i++) {
    // If the current digit is less than the last digit in the result vector
    // then remove the last digit from the result vector
    // k>0 is used to make sure that we remove only k digits
    // result.back() > num[i] is used to make sure that we remove only the last
    // digit
    while (!result.empty() && num[i] < result.back() && k > 0) {
      // Remove the last digit from the result vector
      result.pop_back();
      // k is decremented because we have removed a digit
      k--;
    }
    // Push the current digit to the result vector
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
  // Test cases
  cout << removeKdigits("1432219", 3) << endl;    // Output: "1219"
  cout << removeKdigits("10200", 1) << endl;      // Output: "200"
  cout << removeKdigits("10", 2) << endl;         // Output: "0"
  cout << removeKdigits("10", 1) << endl;         // Output: "0"
  cout << removeKdigits("112", 1) << endl;        // Output: "11"
  cout << removeKdigits("1234567890", 9) << endl; // Output: "0"
  return 0;
}