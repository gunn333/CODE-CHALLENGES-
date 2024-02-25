//! Sort Characters By Frequency (Leetcode 451)

// Question Link:
// https://leetcode.com/problems/sort-characters-by-frequency/

#include <bits/stdc++.h>
using namespace std;

string frequencySort(string s) {
  vector<int> freq(150, 0);

  for (int i = 0; i < s.size(); i++) {
    freq[s[i]]++;
  }
  int max = INT_MIN, max_index = -1;

  string res = "";
  while (res.size() != s.size()) {
    for (int i = 0; i < freq.size(); i++) {
      if (freq[i] != 0 && max < freq[i]) {
        max = freq[i];
        max_index = i;
      }
    }
    freq[max_index] = 0;
    while (max--)
      res += (max_index);
  }
  return res;
}

int main() {
  string s = "tree";
  cout << frequencySort(s) << endl;
  return 0;
}