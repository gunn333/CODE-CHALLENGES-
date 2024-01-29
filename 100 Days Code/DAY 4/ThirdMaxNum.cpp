//! Third Maximum Number

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int thirdMax(vector<int> &nums) {
  // sort as desc
  sort(nums.begin(), nums.end(), greater<int>());
  int count = 1;
  int ans = nums[0];

  for (int i = 1; i < nums.size(); ++i) {
    if (nums[i] != nums[i - 1]) {
      count++;
      ans = nums[i];
    }

    if (count == 3) {
      return ans;
    }
  }

  // return the maximum if less than 3 distinct maximums
  return nums[0];
}

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  cout << thirdMax(nums) << endl;
  return 0;
}