//! Missing Element Of AP

#include <iostream>
using namespace std;
int findMissing(int arr[], int n) {
  int ans;
  int last = arr[n - 1];
  int first = arr[0];
  int diff =
      (last - first) / n; // To get the difference between each element in AP

  for (int i = 0; i < n; i++) {
    int add = arr[i] + diff;
    if (add != arr[i + 1]) // We are checking if current element+difference
                           // should be equal to next element
      return add; // If its not equal then return the sum of current element and
                  // difference
  }
  return -1;
}
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cout << findMissing(arr, n);
  return 0;
}