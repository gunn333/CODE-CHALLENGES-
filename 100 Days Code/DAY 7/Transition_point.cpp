//! Transition point geeksforgeeks

#include <iostream>
using namespace std;
int transition_point(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == 1) {
      return i;
    }
  }
  return -1;
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
  cout << "Transition point is: " << transition_point(arr, n);
  return 0;
}