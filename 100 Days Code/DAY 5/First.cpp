//! Find First and Last Position of Element in Sorted Array

#include <iostream>
#include <vector>
using namespace std;
vector<int> searchRange(vector<int> &nums, int target) {
  int first = -1;
  int last = -1;
  int n = nums.size();
  for (int i = 0; i < n; ++i) {
    if (nums[i] == target) {
      if (first == -1) {
        first = i;
      }
      last = i;
    }
  }
  return {first, last};
}
int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  int target;
  cin >> target;
  vector<int> ans = searchRange(nums, target);
  cout << ans[0] << " " << ans[1] << endl;
  return 0;
}
