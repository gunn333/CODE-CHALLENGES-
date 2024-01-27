#include <iostream>
using namespace std;
int BinarySearch(int n, int arr[], int key) {
  int start = 0;
  int end = n - 1;
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (arr[mid] == key) {
      return mid;
    } else if (arr[mid] > key) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return -1;
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  int key;
  cout << "Enter the key to be searched: ";
  cin >> key;
  int index = BinarySearch(n, arr, key);
  cout << "Element found at index: " << index << endl;
  return 0;
}