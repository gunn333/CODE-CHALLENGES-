//! Segregate even and odd values in an array
// Question Link:
// https://www.geeksforgeeks.org/problems/segregate-even-and-odd-numbers4629/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

#include <bits/stdc++.h>
using namespace std;
void segregateEvenOdd(int arr[], int n) {
  vector<int> even;
  vector<int> odd;
  for (int i = 0; i < n; i++) {
    if (arr[i] % 2 == 0) {
      even.push_back(arr[i]);
    } else {
      odd.push_back(arr[i]);
    }
  }
  std::sort(even.begin(), even.end());
  std::sort(odd.begin(), odd.end());
  copy(even.begin(), even.end(), arr);
  copy(odd.begin(), odd.end(), arr + even.size());
  // arr + even.size() is the starting point for the odd numbers.
}
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  segregateEvenOdd(arr, n);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}