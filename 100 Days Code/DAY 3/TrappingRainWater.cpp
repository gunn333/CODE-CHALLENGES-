//! Trapping Rain Water Problem

#include <iostream>
#include <vector>
using namespace std;
int trap(vector<int> &height) {
  int n = height.size();
  vector<int> lmax(n, height[0]);
  vector<int> rmax(n, height[n - 1]);

  for (int i = 1; i < n - 1; i++) {
    int temp = max(height[i], lmax[i - 1]);
    lmax[i] = temp;
  }

  for (int i = n - 2; i >= 0; i--) {
    int temp = max(height[i], rmax[i + 1]);
    rmax[i] = temp;
  }

  int ans = 0;
  for (int i = 1; i < n - 1; i++) {
    ans = ans + min(lmax[i], rmax[i]) - height[i];
  }

  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> height(n);
  for (int i = 0; i < n; i++)
    cin >> height[i];
  cout << trap(height) << endl;
  return 0;
}