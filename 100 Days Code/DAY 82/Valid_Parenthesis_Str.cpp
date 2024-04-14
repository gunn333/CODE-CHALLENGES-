//! Valid Parenthesis String (Leetcode 678)

// Question Link:
// https://leetcode.com/problems/valid-parenthesis-string/

#include <bits/stdc++.h>
using namespace std;

bool checkValidString(string s) {
  vector<char> st;    // vector of open bracket and star.
  int count_open = 0; // count of open brackets.

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ')') {
      if (st.empty())
        return false;
      else {
        if (count_open == 0)
          st.pop_back();
        else {
          for (int i = st.size() - 1; i >= 0; i--) {
            if (st[i] == '(') {
              count_open -= 1;
              st.erase(st.begin() + i);
              break;
            }
          }
        }
      }
    } else if (s[i] == '(') {
      st.push_back('(');
      count_open += 1;
    } else
      st.push_back('*');
  }

  int count_astr = 0; // count of *.
  // checking for extra open bracket if open cancel with star.
  for (int i = st.size() - 1; i >= 0; i--) {
    if (st[i] == '*')
      count_astr += 1;
    else {
      count_astr -= 1;
      if (count_astr < 0)
        return false;
    }
  }
  return true;
}
