//! Greater on right side geekforgeeks

#include <bits/stdc++.h>
using namespace std;

void nextGreatest(int arr[], int n) {
  // code here
  int maxnum = -1;
  for (int i = n - 1; i >= 0; i--) {
    int curr_ele = arr[i];
    arr[i] = maxnum;
    maxnum = max(maxnum, curr_ele);
  }
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  nextGreatest(arr, n);
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  return 0;
}