// Question Link: https://www.geeksforgeeks.org/problems/union-of-two-arrays3538/1

#include <iostream>
#include <unordered_set>
using namespace std;

int doUnion(int a[], int n, int b[], int m) {
  unordered_set<int> s;
  for (int i = 0; i < n; i++)
    s.insert(a[i]);
  for (int i = 0; i < m; i++)
    s.insert(b[i]);
  return s.size();
}

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int m;
  cin >> m;
  int b[m];
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  cout << doUnion(a, n, b, m) << endl;
  return 0;
}
