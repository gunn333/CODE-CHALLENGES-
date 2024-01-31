//! Find missing and repeating element in an array

#include <iostream>
#include <vector>
using namespace std;
vector<int> findTwoElement(vector<int> arr, int n) {
  // code here
  int Xor = 0;
  for (int i = 0; i < n; i++) {
    Xor ^= arr[i];
    Xor ^= i + 1;
  }
  int bitNo = 0;
  while (1) {
    if ((Xor & (1 << bitNo)) != 0) break;
    bitNo++;
  }

  int one = 0, zero = 0;
  for (int i = 0; i < n; i++) {
    if ((arr[i] & (1 << bitNo)) != 0)
      one ^= arr[i];
    else
      zero ^= arr[i];
    if ((i + 1 & (1 << bitNo)) != 0)
      one ^= i + 1;
    else
      zero ^= i + 1;
  }

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (zero == arr[i]) cnt++;
  }
  if (cnt == 2) return {zero, one};
  return {one, zero};
}
int main() {
  int n;
  cout << "Enter the size of array: ";
  cin >> n;
  vector<int> arr(n);
  cout << "Enter the elements of array: ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  vector<int> ans = findTwoElement(arr, n);
  cout << "Missing element is: " << ans[0] << endl;
  cout << "Repeating element is: " << ans[1] << endl;
  return 0;
}
