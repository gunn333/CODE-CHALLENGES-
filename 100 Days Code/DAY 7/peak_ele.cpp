//! Peak Element is the element which is greater than its neighbours

#include <climits>
#include <iostream>
using namespace std;
int peak_ele(int arr[], int n) {
  /*
  for (int i = 0; i < n; i++) {
       if (arr[i] > arr[i + 1]) {
         return i;
       }
     }
     return n - 1;
  */
  int maxnum = INT_MIN;
  int temp;
  for (int i = 0; i < n; i++) {
    if (arr[i] > maxnum) {
      maxnum = arr[i];
      temp = i;
    }
  }
  return temp;
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
  cout << "Peak Element is: " << peak_ele(arr, n);
  return 0;
}