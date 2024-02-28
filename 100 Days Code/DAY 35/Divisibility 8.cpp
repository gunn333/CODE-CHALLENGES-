//! Divisibliity by 8 (gfg POTD)

// Question Link:
// https://www.geeksforgeeks.org/problems/check-if-a-number-is-divisible-by-83957/1

#include <iostream>
#include <vector>
using namespace std;

int DivisibleByEight(string s) {
  int n = s.length();
  string ans = s;
  if (n >= 3) {
    // Extracting the last three strings from s and storing it in ans string
    ans = s[n - 3];
    ans += s[n - 2];
    ans += s[n - 1];
  }
  // Now i am converting the string ans to integer and checking if it is
  // divisible by 8
  int res = stoi(ans);
  return res % 8 == 0 ? 1 : -1;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    cout << DivisibleByEight(s) << endl;
  }
  return 0;
}

/*
According to the divisibility by 8 rule, if the last three numbers are zero
or divisible by 8, the whole number is divisible by 8.
*/