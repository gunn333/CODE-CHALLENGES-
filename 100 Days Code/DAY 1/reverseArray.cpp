#include <iostream>
#include <vector>
using namespace std;

vector<int> reverseArray(int n, vector<int> &nums) {
  int start = 0;
  int end = n - 1;
  while (start <= end) {
    swap(nums[start], nums[end]);
    start++;
    end--;
  }
  return nums;
}

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  vector<int> ans = reverseArray(n, nums);
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
