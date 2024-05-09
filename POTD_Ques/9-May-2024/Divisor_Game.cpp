//! Divisor Game (GeeeksforGeeks)

// Question Link:
// https://www.geeksforgeeks.org/problems/divisor-game-1664432414/1

#include <bits/stdc++.h>
using namespace std;

bool divisorGame(int n) {
  // If the number is even, Alice wins
  if (n % 2 == 0) {
    return true;
  }
  // If the number is odd, Bob wins
  return false;
}

int main() {
  int n = 6;
  cout << (divisorGame(n) ? "Alice" : "Bob") << " wins" << endl;
  return 0;
}