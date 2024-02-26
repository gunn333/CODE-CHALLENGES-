//! Detect Capital (LeetCode 520)

// Question Link:
// https://leetcode.com/problems/detect-capital/

#include <bits/stdc++.h>
using namespace std;

bool detectCapitalUse(string word) {
  vector<int> v;
  string s1 = "abcdefghijklmnopqrstuvwxyz";
  string s2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  long long int n = word.size(), upper = 0, lower = 0;
  for (int i = 0; i < n; i++) {
    // find lowercase letters in string word
    int found = s1.find(word[i]);
    if (found == string::npos) {
      // count upper case letters
      upper++;
      // position of the uppercase letter
      v.push_back(i);
    } else {
      // count lowercase letters
      lower++;
    }
  }

  if (upper == n || (upper == 1 && v[0] == 0) || lower == n) {
    return true;
  } else
    return false;
}

int main() {
  string s;
  cin >> s;
  cout << detectCapitalUse(s) << endl;
  return 0;
}