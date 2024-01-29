//! Divide Array into Equal Pairs

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool divideArray(vector<int> &nums) {
  sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size() - 1; i = i + 2) {
    if (nums[i] != nums[i + 1]) {
      return false;
    }
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  cout << (divideArray(nums) ? "true" : "false") << endl;
  return 0;
}