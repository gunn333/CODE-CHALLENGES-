/*
Check if a string is a pangram or not means it contains all 26 alphabets or not
Question Link:
https://www.geeksforgeeks.org/problems/pangram-checking-1587115620/1
*/

// ! POTD of 1 February 2024 geeksforgeeks

#include <bits/stdc++.h>
using namespace std;
bool checkPangram(string s) {
  set<char> res;
  for (int i = 0; i < s.length(); i++) // iterating over string
  {
    s[i] = tolower(s[i]);             // all the characters will be treated same
    if (s[i] >= 'a' && s[i] <= 'z') { // if the character is an alphabet
      res.insert(s[i]);
    } else
      continue; // if the character is not an alphabet
  }
  return res.size() == 26;
  /*
  if the size of set is 26 then it is a pangram and return true = 1
  */
}