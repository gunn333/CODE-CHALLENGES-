#include <iostream>
#include <vector>
using namespace std;

void segregateElements(int arr[], int n) {
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (arr[i] >= 0) {
      ans.push_back(arr[i]);
    }
  }
  for (int i = 0; i < n; i++) {
    if (arr[i] < 0) {
      ans.push_back(arr[i]);
    }
  }
  for (int i = 0; i < n; i++) {
    arr[i] = ans[i];
  }
  return;
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  segregateElements(arr, n);
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
  return 0;
}