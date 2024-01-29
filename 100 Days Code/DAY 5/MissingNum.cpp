//! Missing Number

#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int> &nums) {
  int n = nums.size();
  int res = 0;
  for (int i = 0; i <= n; i++) {
    res = res ^ i;
  }
  for (int i = 0; i < n; i++) {
    res = nums[i] ^ res;
  }
  return res;
}
int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  cout << missingNumber(nums) << endl;
  return 0;
}