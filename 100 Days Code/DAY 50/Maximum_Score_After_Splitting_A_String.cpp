//! Maximum Score After Splitting A String (LeetCode 1422)

// Question Link:
// https://leetcode.com/problems/maximum-score-after-splitting-a-string/

#include <bits/stdc++.h>
using namespace std;

int maxScore(string s) {
  int oneCount = 0;
  int zeroCount = 0;
  int score = -1;
  int currScore;

  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == '1') {
      ++oneCount;
    }
  }

  for (int i = 0; i < s.length() - 1; ++i) {
    if (s[i] == '0') {
      ++zeroCount;
    } else {
      --oneCount;
    }

    currScore = zeroCount + oneCount;

    if (currScore > score) {
      score = currScore;
    }
  }

  return score;
}

int main() {
  string s = "011101";
  cout << maxScore(s) << endl;
  return 0;
}