//! Search in Rotated Sorted Array

#include <bits/stdc++.h>
using namespace std;
int search(vector<int> &nums, int target) {
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == target)
      return i;
  }
  return -1;
}
int main() {
  int n, target;
  cin >> n >> target;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cout << search(arr, target);
  return 0;
}