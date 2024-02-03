#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int maxSubarraySum(vector<int> &nums) {
  int n = nums.size();
  int maxSum = INT_MIN, currSum = 0;
  for (int i = 0; i < n; i++) {
    currSum = max(nums[i], currSum + nums[i]);
    maxSum = max(maxSum, currSum);
  }
  return maxSum;
}

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  cout << maxSubarraySum(nums) << endl;
  return 0;
}
