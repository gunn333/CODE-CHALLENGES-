//! Reverse Prefix of Word (Leetcode 2000)

// Question Link :
// https://leetcode.com/problems/reverse-prefix-of-word/

#include <bits/stdc++.h>
using namespace std;

string reversePrefix(string word, char ch) {
  // Size of the word
  int n = word.size();
  // v vector will store the prefix of the word till the character ch
  vector<char> v;
  // found will be true if the character ch is found in the word
  bool found = false;
  for (int i = 0; i < n; i++) {
    // Push the characters in the vector v
    v.push_back(word[i]);
    // If the character ch is found in the word
    if (word[i] == ch) {
      found = true;
      // Reverse the vector v from the beginning till the character ch
      reverse(v.begin(), v.end());
      break;
    }
  }
  if (!found) {
    return word;
  }
  // Convert the vector v to string
  string ans(v.begin(), v.end());
  // .substr(v.size()) will give the remaining part of the word after the
  // character ch
  // .substr function will return the substring of the word starting from the
  // index v.size()
  // ans += word.substr(v.size()) will append the remaining part of the word to
  // the ans
  ans += word.substr(v.size());
  return ans;
}

int main() {
  // Test case 1
  string word = "abcdef";
  char ch = 'd';
  cout << reversePrefix(word, ch) << endl;
  // Test case 2
  word = "xyxzxe";
  ch = 'z';
  cout << reversePrefix(word, ch) << endl;
  // Test case 3
  word = "abcd";
  ch = 'z';
  cout << reversePrefix(word, ch) << endl;
  return 0;
}