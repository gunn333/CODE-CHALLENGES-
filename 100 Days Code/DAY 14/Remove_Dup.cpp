//! Remove Duplicates from String

// Question Link:
// https://www.geeksforgeeks.org/problems/remove-all-duplicates-from-a-given-string4321/1?page=1&difficulty%5B%5D=0&category%5B%5D=Strings&sortBy=submissions

#include <iostream>
#include <set>
#include <string>
using namespace std;

string removeDuplicates(string str) {

  string res = "";
  for (int i = 0; i < str.size(); i++) {
    if (res.find(str[i]) == string::npos) {
      res.push_back(str[i]);
    }
  }

  return res;
}

int main() {
  string str = "geeksforgeeks";
  cout << removeDuplicates(str) << endl;
  return 0;
}

/*
Alternate Solution:
set<char> st;
  string ans = "";
  for (int i = 0; i < s.size(); i++) {
    if (st.count(s[i]) == 0) {
      st.insert(s[i]);
      ans += s[i];
    }
  }
  return ans;
*/