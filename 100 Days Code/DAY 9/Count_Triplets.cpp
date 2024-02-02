//! Count triplets with sum smaller than X

#include <bits/stdc++.h>
using namespace std;
long long countTriplets(long long arr[], int n, long long sum) {
  long long totalTriplets = 0;
  int left, right, curr_sum;
  sort(arr, arr + n);
  for (int start = 0; start < n; start++) {
    left = start + 1, right = n - 1;
    while (left < right) {
      /*
      right is last element where left is traversing from 1 index to right - 1
      */
      curr_sum = arr[start] + arr[left] + arr[right];
      if (curr_sum < sum) {
        totalTriplets += right - left;
        left++;
        right++;
      }
      right--;
    }
  }

  return totalTriplets;
}

int main() {
  int n;
  cin >> n;
  long long arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long long sum;
  cin >> sum;
  cout << countTriplets(arr, n, sum) << endl;
  return 0;
}
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// Question Link:
// https://www.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1?page=2&difficulty%5B%5D=1&category%5B%5D=Arrays&sortBy=submissions