//! Count Zeros

// Question Link:
// https://www.geeksforgeeks.org/problems/count-the-zeros2550/1?page=1&difficulty%5B%5D=0&category%5B%5D=Searching&sortBy=submissions

#include <iostream>
using namespace std;
int countZeroes(int arr[], int n) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == 0) {
      count++;
    }
  }
  return count;
}
int main() {
  int arr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << countZeroes(arr, n);
  return 0;
}