//! Merge two strings alternatively

// Question Link:
// https://www.geeksforgeeks.org/problems/merge-two-strings2736/1?page=1&difficulty%5B%5D=-1&category%5B%5D=Strings&sortBy=submissions

#include <iostream>
#include <string>
#include <vector>
using namespace std;
string merge(string S1, string S2) {
  vector<char> s1;
  vector<char> s2;
  string str = "";
  for (int i = 0; i < S1.size(); i++) {
    s1.push_back(S1[i]);
  }
  for (int i = 0; i < S2.size(); i++) {
    s2.push_back(S2[i]);
  }
  int idx = S1.size() + S2.size();
  for (int i = 0; i < idx; i++) {
    if (!s1.empty()) {
      str = str + s1[0];
      s1.erase(s1.begin());
    }
    if (!s2.empty()) {
      str = str + s2[0];
      s2.erase(s2.begin());
    }
  }
  return str;
}
int main() {
  string str1, str2;
  cin >> str1 >> str2;
  cout << merge(str1, str2);
  return 0;
}