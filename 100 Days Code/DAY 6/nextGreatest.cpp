//! Next Greatest Element geekforgeeks

#include <bits/stdc++.h>
using namespace std;
void nextGreatest(int arr[], int n) {
  int maxnum = -1;
  for (int i = n - 1; i >= 0; i--) {
    int Curr_ele = arr[i];
    arr[i] = maxnum;
    maxnum = max(maxnum, Curr_ele);
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