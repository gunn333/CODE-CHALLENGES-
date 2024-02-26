//! Student Attendance Record I (LeetCode 551)

// Question Link:
// https://leetcode.com/problems/student-attendance-record-i/

#include <bits/stdc++.h>
using namespace std;

bool checkRecord(string s) {
  int aCount = 0;
  int lCount = 0;

  vector<char> num;
  vector<int> num2;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'A') {
      num.push_back(s[i]);
      if (num.size() >= 2) {
        return false;
      }
    }
    if (s[i] == 'L') {
      lCount++;
    }
    if (s[i] != 'L') {
      lCount = 0;
    }

    if (lCount == 3) {
      return false;
    }
  }

  return true;
}

int main() {
  string s;
  cin >> s;
  cout << checkRecord(s) << endl;
  return 0;
}