//! Rearrange an array with O(1) extra space

#include <iostream>
using namespace std;
void rearrange(int arr[], int n) {
  int Cp_arr[n];              // Copy of arr
  copy(arr, arr + n, Cp_arr); // Copying arr to Cp_arr
  for (int i = 0; i < n; i++) {
    arr[i] = Cp_arr[Cp_arr[i]];
    /*
    For example:
    arr[] = {1, 3, 0, 2}
    Cp_arr[] = {1, 3, 0, 2}
    arr[0] = 1
    Cp_arr[0] = 1
    Cp_arr[Cp_arr[0]] = Cp_arr[1] = 3
    arr[0] = 3
    */
  }
}