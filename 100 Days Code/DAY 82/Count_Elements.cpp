//! Count The Elements (GeeksForGeeks)

// Question Link:
// https://www.geeksforgeeks.org/problems/count-the-elements1529/1

#include <bits/stdc++.h>
using namespace std;

vector<int> countElements(vector<int> &a, vector<int> &b, int n,
                          vector<int> &query, int q) {
  vector<int> ans;
  sort(b.begin(), b.end());
  for (int i = 0; i < q; i++) {
    ans.push_back(upper_bound(b.begin(), b.end(), a[query[i]]) - b.begin());
  }
  return ans;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a, b, ans;
    int input;
    for (int i = 0; i < n; i++) {
      cin >> input;
      a.push_back(input);
    }
    for (int i = 0; i < n; i++) {
      cin >> input;
      b.push_back(input);
    }
    int q;
    cin >> q;
    vector<int> query;
    for (int i = 0; i < q; i++) {
      cin >> input;
      query.push_back(input);
    }
    ans = countElements(a, b, n, query, q);
    for (int i = 0; i < q; i++) {
      cout << ans[i] << " ";
    }
    cout << endl;
  }
  return 0;
}