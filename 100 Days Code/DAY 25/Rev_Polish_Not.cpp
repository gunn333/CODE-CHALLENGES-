//! Reverse Polish Notation (Leetcode 150)

// Question Link:
// https://leetcode.com/problems/evaluate-reverse-polish-notation/

#include <bits/stdc++.h>
using namespace std;
int evalRPN(vector<string> &tokens) {
  vector<int> a;
  for (int i = 0; i < tokens.size(); i++) {
    if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" ||
        tokens[i] == "/") {
      int x = a.back();
      a.pop_back();
      int y = a.back();
      a.pop_back();
      if (tokens[i][0] == '+') {

        a.push_back(x + y);
      }
      if (tokens[i][0] == '-') {

        a.push_back(y - x);
      }
      if (tokens[i][0] == '*') {
        a.push_back(x * y);
      }
      if (tokens[i][0] == '/') {
        a.push_back(y / x);
      }
    } else
      a.push_back(stoi(tokens[i]));
  }
  return a[a.size() - 1];
}
int main() {
  int n;
  cin >> n;
  vector<string> tokens(n);
  for (int i = 0; i < n; i++)
    cin >> tokens[i];
  cout << evalRPN(tokens) << endl;
  return 0;
}