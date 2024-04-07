//! Maximum Nesting Depth of Parentheses (Leetcode 1614)

// Question Link:
// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

#include <bits/stdc++.h>
using namespace std;

int maxDepth(string s) {
  int maxDepth = 0;
  // Current depth = parenthesis pair depth
  int currentDepth = 0;
  for (int i = 0; i < s.size(); i++) {
    // Jab bhi ( milta hai toh currentDepth badhao because ( ke baad ) hi aayega
    // so currentDepth will be the depth of the parenthesis () pair
    if (s[i] == '(') {
      currentDepth++;
      // maxDepth will be the maximum of all the currentDepth
      maxDepth = max(maxDepth, currentDepth);
    } else if (s[i] == ')') {
      // Jab bhi ) milta hai toh currentDepth kam karo because ) ke baad
      // currentDepth wil be done as pair is finished
      currentDepth--;
    }
  }
  return maxDepth;
}

int main() {
  string s = "(1+(2*3)+((8)/4))+1";
  cout << maxDepth(s) << endl;
  return 0;
}