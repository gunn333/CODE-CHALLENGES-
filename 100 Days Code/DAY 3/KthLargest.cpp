#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int findKthLargest(vector<int> &nums, int k) {
  sort(nums.begin(), nums.end());

  int i = nums.size() - k;

  return nums[i];
}
int main() {
  vector<int> nums = {3, 2, 1, 5, 6, 4};
  int k = 2;
  cout << findKthLargest(nums, k);
  return 0;
}
