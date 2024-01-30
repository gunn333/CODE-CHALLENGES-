//! Remove Duplicate Elements From Array
#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> arr, int n) {
  set<int> s;
  for (int i = 0; i < n; i++) {
    s.insert(arr[i]);
  }
  copy(s.begin(), s.end(), arr.begin());
  return s.size();
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  int res = removeDuplicates(arr, n);
  cout << res << endl;
  for (int i = 0; i < res; i++) cout << arr[i] << " ";
  return 0;
}