//! Rearrange the array in alternating positive and negative items

#include <iostream>
#include <vector>
using namespace std;
void rearrange(int arr[], int n) {
  vector<long long> v;
  for (int i = 0; i < n; i++) {
    v.push_back(arr[n - i - 1]);
    v.push_back(arr[i]);
  }

  for (int i = 0; i < n; i++) {
    arr[i] = v[i];
  }
}
int main() {
  int n;
  cout << "Enter the size of array: ";
  cin >> n;
  int arr[n];
  cout << "Enter the elements of array: ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  rearrange(arr, n);
  cout << "Rearranged array is: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}