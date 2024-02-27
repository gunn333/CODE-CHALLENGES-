//! Teemo Attacking (LeetCode 495)

// Question Link :
// https://leetcode.com/problems/teemo-attacking/

#include <bits/stdc++.h>
using namespace std;

int findPoisonedDuration(vector<int> &ti, int du) {
  vector<pair<int, int>> vec;
  if (ti.size() == 0)
    return 0;
  for (int i = 0; i < ti.size(); i++) {
    vec.push_back(make_pair(ti[i], ti[i] + du));
  }
  sort(vec.begin(), vec.end());
  int index = 0;
  for (int i = 1; i < vec.size(); i++) {

    if (vec[index].second >= vec[i].first) {

      vec[index].second = max(vec[index].second, vec[i].second);
      vec[index].first = min(vec[index].first, vec[i].first);
    } else {
      index++;
      vec[index] = vec[i];
    }
  }
  int ans = 0;
  for (int i = 0; i <= index; i++)
    ans += (vec[i].second - vec[i].first);
  return ans;
}

int main() {
  vector<int> ti = {1, 4};
  int du = 2;
  cout << findPoisonedDuration(ti, du) << endl;
  return 0;
}