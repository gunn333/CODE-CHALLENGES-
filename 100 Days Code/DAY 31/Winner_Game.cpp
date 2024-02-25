//! Winner of Array Game (LeetCode 1535)

// Question Link:
// https://leetcode.com/problems/find-the-winner-of-an-array-game/description/?envType=daily-question&envId=2024-02-23

#include <bits/stdc++.h>
using namespace std;

int getWinner(vector<int> &arr, int k) {
  int first = arr[0];
  int winner = 0;
  for (int i = 1; i < arr.size(); i++) {
    if (arr[i] > first) {
      first = arr[i];
      winner = 1;
    } else {
      winner++;
    }
    if (winner == k) {
      return first;
    }
  }
  return first;
}

int main() {
  vector<int> arr = {2, 1, 3, 5, 4, 6, 7};
  int k = 2;
  cout << getWinner(arr, k) << endl;
  return 0;
}

/*
LOGIC I USED:

-> The variable `first` is initialized with the value of the first element in
the array `arr`.

-> The variable `winner` is initialized with `0`, indicating the number of
consecutive wins by the current winner.

-> Then, a loop iterates over the elements of the array starting from the second
element (`i = 1`).

-> Inside the loop:

  -> If the current element (`arr[i]`) is greater than `first`, it means that
the current player is winning. So, we update `first` to be equal to `arr[i]`,
and we set `winner` to `1` to indicate that this player has won one game.

  -> Otherwise, if the current player did not win, we increment the `winner`
  count.

  -> If the `winner` count reaches `k`, indicating that the same player has won
  `k` consecutive games, we return the value of `first`, which represents the
  winner.

-> If the loop completes without finding a winner after iterating through all
elements, we return the value of `first`, which represents the winner with the
highest score.
*/