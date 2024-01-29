
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
#define ll long long

class Solution {
public:
  // Function to check if two arrays are equal or not.
  bool check(vector<ll> A, vector<ll> B, int N) {
    // code here
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for (int i = 0; i < N; i++) {
      if (A[i] != B[i]) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<ll> arr(n, 0), brr(n, 0);
    for (ll i = 0; i < n; i++)
      cin >> arr[i];
    for (ll i = 0; i < n; i++)
      cin >> brr[i];
    Solution ob;
    cout << ob.check(arr, brr, n) << "\n";
  }
  return 0;
}
