//! check if all A's are before B's (Leetcode 2124)

// Question Link :
// https://leetcode.com/problems/check-if-all-as-are-before-bs/

#include <bits/stdc++.h>
using namespace std;

bool checkString(string s) {
  vector<char> v;
  for (int i = 0; i < s.length(); i++) {

    v.push_back(s[i]);
  }
  vector<char> copy_v = v;
  sort(copy_v.begin(), copy_v.end());
  if (copy_v == v) {
    return true;
  }
  return false;
}

int main() {
  string s;
  cin >> s;
  cout << checkString(s) << endl;
  return 0;
}

/*
Logic:
1. Created a vector v to store the characters of the string in the same order as
they are present in the string.
2. Created a copy of the vector v and sorted it.
3. If the sorted vector is equal to the original vector then it means that all
A's are before B's in the original vector as well and we return true.
4. Else we return false.
*/