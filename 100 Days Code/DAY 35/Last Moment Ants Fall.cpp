//! Last Moment Before All Ants Fall Out of a Plank (Leetcode 1503)

// Question Link:
// https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/

#include <iostream>
#include <vector>
using namespace std;

int getLastMoment(int n, vector<int> &left, vector<int> &right) {
  // res will store the maximum time taken by the ants to fall
  int res = 0;
  for (int i = 0; i < left.size(); i++)
    res = max(res, left[i]);
  for (int i = 0; i < right.size(); i++)
    res = max(res, n - right[i]);
  return res;
}

int main() {
  int n;
  cin >> n;
  int m;
  cin >> m;
  vector<int> left(m);
  vector<int> right(m);
  for (int i = 0; i < m; i++)
    cin >> left[i];
  for (int i = 0; i < m; i++)
    cin >> right[i];
  cout << getLastMoment(n, left, right);
  return 0;
}