//! Minimum Subset of an array

#include <algorithm>
#include <iostream>
using namespace std;
int numofsubset(int arr[], int n) {

  sort(arr, arr + n);
  int count = 0; // count the number of subsets
  for (int i = 0; i < n; i++) {
    if (arr[i] + 1 == arr[i + 1]) {
      // if the next element is consecutive
      /*
      1 2 3 4 5 6 7 8 9
      arr[i] = 1
      arr[i] + 1 = 2
      arr[i+1] = 2
      so, 1 and 2 are consecutive
      */
      continue;
    } else {
      count++;
    }
  }
  return count;
}