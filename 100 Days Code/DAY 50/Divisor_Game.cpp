//! Divisor Game (LeetCode 1025)

// Question Link:
// https://leetcode.com/problems/divisor-game/

#include <bits/stdc++.h>
using namespace std;

bool divisorGame(int n) {
  if (n % 2 == 0)
    return true;
  else
    return false;
}

int main() {
  int n = 2;
  cout << divisorGame(n) << endl;
  return 0;
}