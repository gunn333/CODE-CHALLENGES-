//! Determine if String Halves Are Alike (LeetCode 1704)

// Question Link:
// https://leetcode.com/problems/determine-if-string-halves-are-alike/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool halvesAreAlike(string s) {
  int sum1 = 0;
  int sum2 = 0;
  int n = s.size();
  vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

  for (int i = 0; i < n / 2; i++) {
    // s[i] != vowels.end() means s[i] is present in vowels
    // vowels.end() ka mtlb hai ki s[i] vowels mei nahi hai
    if (find(vowels.begin(), vowels.end(), s[i]) != vowels.end())
      sum1++;
  }

  for (int i = n / 2; i < n; i++) {
    if (find(vowels.begin(), vowels.end(), s[i]) != vowels.end())
      sum2++;
  }

  return sum1 == sum2;
}

int main() {
  string s = "book";
  cout << halvesAreAlike(s) << endl; // Output: true
  return 0;
}
