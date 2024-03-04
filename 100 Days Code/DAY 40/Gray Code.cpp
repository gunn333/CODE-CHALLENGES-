//! Gray Code (LeetCode 89)

#include <bits/stdc++.h>
using namespace std;

vector<int> grayCode(int n) {
  vector<int> ans;
  //   i<(1<<n) ka mtlb hai ki 2^n tak loop chalega
  //   2^n isliye kyuki har bit ke liye 2 options hote hai 0 or 1
  /*
  For example,
  n = 2
    00
    01
    11
    10
    So, the sequence is [00, 01, 11, 10]
    And humne loop 2^n tak isliye chalaya kyuki as in the above example, we have
  2^2 = 4 numbers
  */
  for (int i = 0; i < (1 << n); ++i) {
    /*
    i >> 1 ka mtlb hai ki i ke binary representation me se last bit ko hata
    do
    For example,
    i = 3
    i ka binary representation = 011
    i >> 1 = 001
    i ^ (i >> 1) = 010
    010 is the gray code of 011
    */
    ans.push_back(i ^ (i >> 1));
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> ans = grayCode(n);
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
