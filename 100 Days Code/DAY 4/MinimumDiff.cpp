//! Minimum Difference B/w Highest and Lowest of K scores
#include <bits/stdc++.h>
using namespace std;

int minimumDifference(vector<int> &nums, int k) {
  int i = 0;
  int j = k - 1;
  sort(nums.begin(), nums.end());
  int n = nums.size();
  int ans = INT_MAX;
  while (j < n) {
    ans = min(ans, nums[j++] - nums[i++]);
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  int k;
  cin >> k;
  cout << minimumDifference(nums, k) << endl;
  return 0;
}