//! Is a power of 2 leeetcode

#include <bits/stdc++.h>
using namespace std;
bool isPowerOfTwo(int n) {
  for (int i = 0; i <= 30; i++) {
    if (pow(2, i) == n) {
      return true;
    }
  }
  return false;
}
int main() {
  int n;
  cout << "Enter the number: ";
  cin >> n;
  cout << isPowerOfTwo(n);
  return 0;
}