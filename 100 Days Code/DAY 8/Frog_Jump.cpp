//! Frogs Jumping Problem geekforgeeks

#include <bits/stdc++.h>
using namespace std;

int unvisitedLeaves(int N, int leaves, int frogs[]) {
  vector<bool> visited(leaves + 1, false);  // Leaves range is from 1
  for (int i = 0; i < N; i++) {             // Traverse through the frogs[]
    int curr_frog = frogs[i];               // Current frog

    if (curr_frog <= leaves &&
        !visited[curr_frog]) {  // If frog is in range of leaves and not visited
      int j = curr_frog;
      while (j <= leaves) {  // Mark all the leaves visited by the frog
        visited[j] = true;
        j += curr_frog;  // Jump to the next leaf
      }
    }
  }

  int ans = 0;                         // Count of unvisited leaves
  for (int i = 1; i <= leaves; i++) {  // Traverse through the leaves
    if (!visited[i]) ans++;            // If leaf is not visited, increment ans
  }

  return ans;
}

int main() {
  int N, leaves;
  cin >> N >> leaves;
  int frogs[N];
  for (int i = 0; i < N; i++) cin >> frogs[i];

  cout << unvisitedLeaves(N, leaves, frogs) << endl;
  return 0;
}