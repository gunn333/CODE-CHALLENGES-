//! Anagram of 2 strings
/*
An anagram of a string is another string that contains the same characters, only
the order of characters can be different.

Question Link:
https://www.geeksforgeeks.org/problems/anagram-of-string/1?page=1&difficulty%5B%5D=-1&category%5B%5D=Strings&sortBy=submissions
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int remAnagram(string str1, string str2) {

  sort(str1.begin(), str1.end());
  sort(str2.begin(), str2.end());
  string ss;

  for (int i = 0; i < str1.size(); i++) {

    int pos = str2.find(str1[i]);
    if (pos == string::npos) {
      ss.push_back(str1[i]);
    } else {
      // Remove character from pos in str2
      str2.erase(pos, 1);
    }
  }
  ss += str2;
  return ss.size();
}
/*
  sort(str1.begin(), str1.end());
  sort(str2.begin(), str2.end());

  string ss;
  Stores the characters that are not common in both strings and
  need to be deleted
  for (int i = 0; i < str1.size(); i++) {
    Checks if str1[i] is present in str2 or not
    Agar nahi hai toh ss mei add kardo
    if (str2.find(str1[i]) == string::npos) {
      ss.push_back(str1[i]);
    } else {
      Agar hai toh str2 se remove kardo by erase function
      str2.erase(str2.begin() + str2.find(str1[i]));
    }
  }
  return str2.size() + ss.size();
*/

int main() {
  string str1, str2;
  cin >> str1 >> str2;
  cout << remAnagram(str1, str2);
  return 0;
}