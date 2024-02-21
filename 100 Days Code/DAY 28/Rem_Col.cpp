//! Remove Colored Pieces if Both neighbors are same (Leetcode 2038)

// Question Link:
// https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/

#include <bits/stdc++.h>
using namespace std;

bool winnerOfGame(string colors) {
  if (colors.size() <= 2)
    return false;
  int countA = 0, countB = 0;
  for (int i = 1; i < colors.size() - 1; i++) {
    if (colors[i - 1] == colors[i] && colors[i] == colors[i + 1]) {
      if (colors[i] == 'A')
        countA++;
      else
        countB++;
    }
  }
  // Alice wins if countA > countB and return true
  return countA > countB;
}

int main() {
  // Test cases
  cout << winnerOfGame("AAABABB") << endl; // Output: true
  cout << winnerOfGame("ABAB") << endl;    // Output: false
  cout << winnerOfGame("AA") << endl;      // Output: false
  return 0;
}