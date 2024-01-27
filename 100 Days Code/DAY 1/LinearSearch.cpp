#include <iostream>
using namespace std;
int linearSearch(int n, int arr[], int key) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == key) {
      return i;
    }
  }
  return -1;
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int key;
  cout << "Enter the key to be searched: ";
  cin >> key;

  int index = linearSearch(n, arr, key);
  cout << "Element found at index: " << index << endl;
  return 0;
}