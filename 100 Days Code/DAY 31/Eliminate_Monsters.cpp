//! Eliminate Monsters (LeetCode 1690)

// Question Link:
// https://leetcode.com/problems/eliminate-maximum-number-of-monsters/description/

#include <bits/stdc++.h>
using namespace std;
int eliminateMaximum(vector<int> &dist, vector<int> &speed) {
  vector<float> come_time;
  for (int i = 0; i < dist.size(); i++) {
    come_time.push_back((float)dist[i] / speed[i]);
  }
  sort(come_time.begin(), come_time.end());
  int result = 0;
  //   i is the time at which we are killing the monsters
  for (int i = 0; i < come_time.size(); i++) {
    /* If come_time[i] <= i, it means ki monster mere marne se pehle hi aa
      jayega
     */
    if (come_time[i] <= i) {
      break;
    }
    // ab tak ke monsters ko mara hua count
    result++;
  }
  return result;
}

int main() {
  vector<int> dist = {1, 3, 4};
  vector<int> speed = {1, 1, 1};
  cout << eliminateMaximum(dist, speed) << endl;
  return 0;
}