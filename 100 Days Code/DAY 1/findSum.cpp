// Question Link: https://www.geeksforgeeks.org/problems/max-min/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

#include <climits>
#include <iostream>

using namespace std;

int findSum(int arr[], int n) {
  int maxno = INT_MIN;
  int minno = INT_MAX;
  for (int i = 0; i < n; i++) {
    maxno = max(maxno, arr[i]);
    minno = min(minno, arr[i]);
  }
  int sum = maxno + minno;
  return sum;
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cout << "Original Array: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  cout << "Sum of Maximum and Minimum element of the array: " << findSum(arr, n)
       << endl;
}
