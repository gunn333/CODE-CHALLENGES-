//! Longest Happy String (LeetCode 1405)

// Question Link:
// https://leetcode.com/problems/longest-happy-string/

#include <bits/stdc++.h>
using namespace std;

string longestDiverseString(int a, int b, int c) {

  string ans = "";

  vector<pair<int, char>> arr;

  if (a != 0) {
    arr.push_back({a, 'a'});
  }

  if (b != 0) {
    arr.push_back({b, 'b'});
  }

  if (c != 0) {
    arr.push_back({c, 'c'});
  }

  int r = arr.size() - 1;
  int l = 0;

  int count = 0;
  int idx = 0;
  while (l <= r) {
    sort(arr.begin(), arr.end());

    if (ans.empty() || (arr[r].second == ans[ans.size() - 1] && count < 2)) {
      ans.push_back(arr[r].second);
      arr[r].first--;
      count++;
    } else if (arr[r].second == ans[ans.size() - 1] && count >= 2) {
      if (l != r) {
        ans.push_back(arr[l].second);
        arr[l].first--;
        count = 1;
      } else {
        break;
      }

      if (arr[l].first == 0) {
        l++;
      }
    } else {
      if (arr[r].second != ans[ans.size() - 1]) {
        ans.push_back(arr[r].second);
        arr[r].first--;
        count = 1;
      }
    }

    sort(arr.begin(), arr.end());

    if (arr[l].first == 0) {
      l++;
    }
  }

  return ans;
}

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  cout << longestDiverseString(a, b, c) << endl;
  return 0;
}