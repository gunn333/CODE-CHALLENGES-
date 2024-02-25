//! Adding Spaces to a string (Leetcode 2109)

// Question Link :
// https://leetcode.com/problems/adding-spaces-to-a-string/

#include <bits/stdc++.h>
using namespace std;

string addSpaces(string s, vector<int> &spaces) {
  string result = "";
  int i = 0, j = 0;
  while (i < s.size()) {
    // If the current index is present in the spaces vector then add a space in
    // the result string and increment the j because we have to check for the
    // next index in the spaces vector
    if (j < spaces.size() && spaces[j] == i) {
      result += ' ';
      j++;
    }
    // Add the other characters to the result string and increment the i
    result += s[i];
    i++;
  }
  return result;
}

int main() {
  string s;
  cin >> s;
  int n;
  cin >> n;
  vector<int> spaces(n);
  for (int i = 0; i < n; i++) {
    cin >> spaces[i];
  }
  cout << addSpaces(s, spaces) << endl;
  return 0;
}