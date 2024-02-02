//! POTD of geekforgeeks

#include <bits/stdc++.h>
using namespace std;
int atoi(string s) {
  int symbol = 1; // 1 for positive and -1 for negative
  int result = 0;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] == '-' && i == 0) { // if the first character is '-'
      symbol = -1;
    } else if (s[i] >= '0' &&
               s[i] <= '9') { // if the character is a digit not a ascii value
      result = result * 10 + (s[i] - '0');
      /*
            s[i] - '0' will give the integer value of the character removing the
         ascii value adding the digit to the result* 10 gives the result in 123
         format not 1,2,3 separately
      */
    } else {
      return -1;
    }
  }
  result = result * symbol; // adding the symbol to the result
  return result;
}
int main() {
  string s;
  cin >> s;
  cout << atoi(s) << endl;
  return 0;
}

/*
Question:
Given a string, s, the objective is to convert it into integer format without
utilizing any built-in functions. If the conversion is not feasible, the
function should return -1.

Link: https://www.geeksforgeeks.org/problems/implement-atoi/1
*/