//! Rings And Rods (Leetcode 2103)

// Question Link :
// https://leetcode.com/problems/rings-and-rods/description/

#include <bits/stdc++.h>
using namespace std;

int countPoints(string rings) {
  vector<int> R(10);
  vector<int> G(10);
  vector<int> B(10);
  //   Incrementing by 2 because we are taking 2 characters at a time
  for (int i = 0; i < rings.size(); i += 2) {
    char curr_color = rings[i];
    // Converting the character to integer
    int rod = rings[i + 1] - '0';

    if (curr_color == 'R') {
      R[rod]++;
    } else if (curr_color == 'B') {
      B[rod]++;
    } else {
      G[rod]++;
    }
  }

  int result = 0;
  for (int i = 0; i < 10; i++) {
    // i is the rod number
    if (R[i] > 0 && G[i] > 0 && B[i] > 0)
      result++;
  }

  return result;
}