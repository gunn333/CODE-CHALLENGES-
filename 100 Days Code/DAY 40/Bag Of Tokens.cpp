//! Bag Of Tokens (Leetcode Daily Problem 948)

// Question Link:
// https://leetcode.com/problems/bag-of-tokens/description/?envType=daily-question&envId=2024-03-04

#include <bits/stdc++.h>
using namespace std;

int bagOfTokensScore(vector<int> &tokens, int power) {
  sort(tokens.begin(), tokens.end());
  int n = tokens.size();
  if (n == 0)
    return 0;
  int score = 0;
  if (tokens[0] <= power) {
    power -= tokens[0];
    score++;
  } else {
    return 0;
  }
  int s = 1, e = n - 1;
  while (s <= e) {
    while (power >= tokens[s]) {
      power -= tokens[s];
      s++;
      score++;
    }
    if (s != e && s < e) {
      power += tokens[e];
      score--;
    }
    e--;
  }
  return score;
}

int main() {
  vector<int> tokens = {100, 200, 300, 400};
  int power = 200;
  cout << bagOfTokensScore(tokens, power) << endl;
  return 0;
}