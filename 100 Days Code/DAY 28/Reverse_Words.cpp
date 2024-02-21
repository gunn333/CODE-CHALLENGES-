//! Reverse Words in a String (LeetCode 151)

// Question Link:
// https://leetcode.com/problems/reverse-words-in-a-string/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

string reverseWords(string s) {
  vector<string> output;

  // create a string to store every string
  string temp = "";
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == ' ') {
      if (temp.length() == 0)
        continue;
      // store the string in output vector
      output.push_back(temp);
      temp = "";
    } else
      temp += s[i];
  }

  // store the string in output vector
  if (temp.length())
    output.push_back(temp);

  // reverse the output array
  reverse(output.begin(), output.end());

  s = "";
  // create a new string and pick it from output
  for (int i = 0; i < output.size(); i++) {
    if (output.size() - 1 == i)
      s += output[i];
    else
      s += output[i] + " ";
  }
  return s;
}

int main() {
  string s = "the sky is blue";
  cout << reverseWords(s) << endl;
  return 0;
}