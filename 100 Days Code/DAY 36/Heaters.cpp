//! Heaters (Leetcode 475)

// Question Link:
// https://leetcode.com/problems/heaters/

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int findRadius(vector<int> &v, vector<int> &a) {
  int n = v.size();
  int m = a.size();

  sort(v.begin(), v.end());
  sort(a.begin(), a.end());

  int ans = INT_MIN;

  for (int i = 0; i < n; i++) {

    int id = lower_bound(a.begin(), a.end(), v[i]) - a.begin();

    if (id == 0) {
      ans = max(ans, a[0] - v[i]);
    }

    else if (id == m) {
      ans = max(ans, v[i] - a[m - 1]);
    }

    else {
      ans = max(ans, min(a[id] - v[i], v[i] - a[id - 1]));
    }
  }
  return ans;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> v(n), a(m);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  cout << findRadius(v, a) << endl;
  return 0;
}