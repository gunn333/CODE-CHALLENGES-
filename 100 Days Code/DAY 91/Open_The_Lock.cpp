//! Open the Lock (LeetCode 752)

// Question Link:
// https://leetcode.com/problems/open-the-lock/

#include <bits/stdc++.h>
using namespace std;

int openLock(vector<string> &deadends, string target) {
  // set to store the deadends because we need to check if the target is a
  // deadend or not
  unordered_set<string> dead(deadends.begin(), deadends.end());
  // if the target is a deadend, return -1
  // count function checks if the element is present in the set
  // like dead.count("0000") checks if "0000" is present in the set dead
  if (dead.count("0000")) {
    return -1;
  }
  // if the target is already at 0000, return 0
  if (target == "0000") {
    return 0;
  }
  // queue to perform BFS
  queue<string> q;
  // push the starting point to the queue
  q.push("0000");
  // set to store the visited nodes
  unordered_set<string> visited;
  // insert the starting point to the visited set
  visited.insert("0000");
  // variable to store the level of the BFS
  int level = 0;
  while (!q.empty()) {
    int size = q.size();
    while (size--) {
      string front = q.front();
      q.pop();
      // if the current node is the target, return the level
      if (front == target) {
        return level;
      }
      // loop through all the 4 digits of the current node
      for (int i = 0; i < 4; i++) {
        // string up is the current node with the ith digit incremented by 1
        string up = front;
        // string down is the current node with the ith digit decremented by 1
        string down = front;
        // up[i] is the ith digit of the current node
        // up[i] - '0' converts the character to an integer value
        // (up[i] - '0' + 1) assigns the incremented value to the ith digit
        // % 10 is used to handle the case when the digit is 9
        // + '0' converts the integer value back to a character
        up[i] = (up[i] - '0' + 1) % 10 + '0';
        // down[i] is the ith digit of the current node
        // down[i] - '0' converts the character to an integer value
        // + 9 is used to decrement the digit by 1 and handle the case when the
        // digit is 0
        // % 10 is used to handle the case when the digit is 0
        // + '0' converts the integer value back to a character
        down[i] = (down[i] - '0' + 9) % 10 + '0';
        // if the up node is not visited and not a deadend, push it to the queue
        if (!visited.count(up) && !dead.count(up)) {
          q.push(up);
          visited.insert(up);
        }
        // if the down node is not visited and not a deadend, push it to the
        // queue
        if (!visited.count(down) && !dead.count(down)) {
          q.push(down);
          visited.insert(down);
        }
      }
    }
    // increment the level
    level++;
  }
  return -1;
}

int main() {
  vector<string> deadends = {"0201", "0101", "0102", "1212", "2002"};
  string target = "0202";
  cout << openLock(deadends, target) << endl;
  return 0;
}