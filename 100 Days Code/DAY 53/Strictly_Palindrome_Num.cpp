//! Strictly Palindrome Number (Leetcode 2396)

// Question Link:
// https://leetcode.com/problems/strictly-palindromic-number/description/

#include <bits/stdc++.h>
using namespace std;

bool palindrome(vector<int> n) {
  //   n.size() - 1 - i is used to get the reverse of the number
  // n[i] != n[n.size() - 1 - i] is used to check if the number is palindrome
  // or not
  for (int i = 0; i < n.size(); i++)
    if (n[i] != n[n.size() - 1 - i])
      return false;
  return true;
}

bool isStrictlyPalindromic(int n) {
  int j = n;
  // we started from 2 because 1 is always a palindrome and ended at j - 1
  // because the number in base 10 is always a palindrome
  for (int i = 2; i < j - 1; i++) {
    vector<int> v;
    // n is the number and j is the base and we are converting the number n to
    // base j
    n = j;
    while (n) {
      int b = n % i;
      v.push_back(b);
      n /= i;
    }
    if (!palindrome(v))
      return false;
  }

  return true;
}

int main() {
  int n;
  cin >> n;
  cout << isStrictlyPalindromic(n) << endl;
  return 0;
}
