//! Find The Fine GeeksForGeeks

#include <bits/stdc++.h>
using namespace std;
long long int totalFine(int n, int date, int car[], int fine[]) {
  long long int sum = 0;
  if (date % 2 == 0) {
    for (int i = 0; i < n; i++) {
      if (car[i] % 2 != 0) sum = sum + fine[i];
    }
  } else {
    for (int i = 0; i < n; i++) {
      if (car[i] % 2 == 0) sum = sum + fine[i];
    }
  }

  return sum;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, date;
    cin >> n >> date;
    int car[n], fine[n];
    for (int i = 0; i < n; i++) cin >> car[i];
    for (int i = 0; i < n; i++) cin >> fine[i];
    cout << totalFine(n, date, car, fine) << endl;
  }
  return 0;
}