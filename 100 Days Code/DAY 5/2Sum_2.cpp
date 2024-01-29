//! Two Sum II - Input array is sorted

#include <iostream>
#include <vector>
using namespace std;
vector<int> twoSum(vector<int> &numbers, int target) {
  int n = numbers.size();
  int start = 0, end = n - 1;
  while (start < end) {
    if (numbers[start] + numbers[end] == target)
      return {start + 1, end + 1};

    else if (numbers[start] + numbers[end] > target)
      end--;
    else
      start++;
  }
  return {};
}
int main() {
  int n;
  cin >> n;
  vector<int> numbers(n);
  for (int i = 0; i < n; ++i) {
    cin >> numbers[i];
  }
  int target;
  cin >> target;
  vector<int> ans = twoSum(numbers, target);
  cout << ans[0] << " " << ans[1] << endl;
  return 0;
}