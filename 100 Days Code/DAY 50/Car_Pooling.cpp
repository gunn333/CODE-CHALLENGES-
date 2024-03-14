//! Car Pooling (LeetCode 1094)

// Question Link:
// https://leetcode.com/problems/car-pooling/

#include <bits/stdc++.h>
using namespace std;

bool carPooling(vector<vector<int>> &trips, int capacity) {
  vector<pair<int, int>> v;

  for (int i = 0; i < trips.size(); i++) {
    // storing the source and number of people who will enter on this
    // source
    v.push_back({trips[i][1], trips[i][0]});
    // storing the destination and number of people who will exit that's
    // why '-' symbol it means these number of people will go out of car.
    v.push_back({trips[i][2], -trips[i][0]});
  }

  // sorting the vector, bcz car will move in one direction, so we want the
  // source to destination in increasing order like, 1 2 3 4 5 6 7 8 9....
  sort(v.begin(), v.end());

  // now we will check if the car is full or not at each point and filled is the
  // number of people in the car at each point
  int filled = 0;

  for (int i = 0; i < v.size(); i++) {
    // v[i].second means number of people who will enter or exit
    filled += v[i].second;
    // if filled is greater than capacity then return false bcz car is full
    if (filled > capacity)
      return false;
  }
  return true;
}

int main() {
  vector<vector<int>> trips = {{2, 1, 5}, {3, 3, 7}};
  int capacity = 4;
  cout << carPooling(trips, capacity) << endl;
  return 0;
}