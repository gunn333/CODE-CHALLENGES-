//! Time needed to buy tickets (LeetCode 2073)

// Question Link:
//

#include <bits/stdc++.h>
using namespace std;

int timeRequiredToBuy(vector<int> &tickets, int k) {
  //  time keeps the track of the time taken to buy the tickets
  int time = 0;
  // index i is used to iterate over the tickets vector
  int i = 0;
  // tickets[k] > 0 means there are tickets available at the kth window
  while (tickets[k] > 0) {
    // tickets[i] > 0 means there are tickets available at the ith window
    if (tickets[i] > 0) {
      // tickets[i]-- will reduce the number of tickets available at the ith
      tickets[i]--;
      // time++ will increase the time taken to buy the tickets
      time++;
    }
    i++;
    // Check if i exceeds the size of the tickets vector. If it does, reset i to
    // 0 to start from the beginning of the vector.
    // After exiting the loop (when tickets[k] becomes 0), return the total time
    // taken to buy all tickets (time).
    if (i >= tickets.size())
      i = 0;
  }
  return time;
}

int main() {
  vector<int> tickets = {2, 6, 3, 4, 5};
  int k = 2;

  cout << timeRequiredToBuy(tickets, k) << endl;
  return 0;
}