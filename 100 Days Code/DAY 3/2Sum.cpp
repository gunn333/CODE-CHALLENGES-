#include <iostream>
#include <vector>
using namespace std;
vector<int> twoSum(vector<int> &nums, int target) {
  int n = nums.size();
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (nums[i] + nums[j] == target) {
        return {i, j};
      }
    }
  }
  return {}; // No solution found
}
int main() {
  int n, target;
  cin >> n >> target;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  vector<int> ans = twoSum(nums, target);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}