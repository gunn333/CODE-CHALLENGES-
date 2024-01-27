#include <iostream>
using namespace std;

void sort012(int a[], int n) {
  int zero = 0, one = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 1)
      one++;
    else if (a[i] == 0)
      zero++;
  }
  for (int i = 0; i < n; i++) {
    if (zero > 0) {
      a[i] = 0;
      zero--;
    } else if (one > 0) {
      a[i] = 1;
      one--;
    } else {
      a[i] = 2;
    }
  }
  return;
}

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort012(a, n);
  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
  cout << endl;
  return 0;
}
