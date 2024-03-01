//! Reverse Vowels (Leetcode 345)

// Question Link:
// https://leetcode.com/problems/reverse-vowels-of-a-string/

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

string reverseVowels(string s) {
  vector<char> v; // Using vector to store vowels
  set<char> st = {'a', 'e', 'i', 'o', 'u',
                  'A', 'E', 'I', 'O', 'U'}; // Using set to check vowels

  for (int i = 0; i < s.size(); i++)
    if (st.find(s[i]) != st.end())
      v.push_back(s[i]); // If vowel, push into vector

  reverse(begin(v), end(v)); // Reverse the vector of vowels

  int j = 0;
  for (int i = 0; i < s.size(); i++)
    if (st.find(s[i]) != st.end())
      s[i] = v[j++]; // If a vowel, keep replacing it and increasing index of v

  return s;
}

int main() {
  string s;
  cin >> s;
  cout << reverseVowels(s) << endl;
  return 0;
}