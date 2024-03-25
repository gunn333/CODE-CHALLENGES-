//! Print N-bti Binary numbers having more 1s than 0s (GeeksForGeeks)

// Question Link:
// https://www.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/1

#include <bits/stdc++.h>
using namespace std;

void help(int n, string s, int countOne, vector<string> &ans) {
  if (n == 0) {
    ans.push_back(s);
    return;
  }
  help(n - 1, s + '1', countOne + 1, ans);
  if (countOne > 0)
    help(n - 1, s + '0', countOne - 1, ans);
}

vector<string> NBitBinary(int n) {
  vector<string> ans;
  help(n, "", 0, ans);
  return ans;
}

int main() {
  int n = 3;
  vector<string> result = NBitBinary(n);
  for (string s : result) {
    cout << s << " ";
  }
  return 0;
}