// Given a sorted array of positive integers. Your task is to rearrange the array elements alternatively i.e first element should be max value, second should be min value, third should be second max, fourth should be second min and so on.


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

/* Question Link :
https://www.geeksforgeeks.org/problems/-rearrange-array-alternately-1587115620/1?page=1&difficulty%5B%5D=1&category%5B%5D=Arrays&sortBy=submissions
*/
