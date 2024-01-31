#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

bool containsDuplicate(vector<int> &nums) {
  unordered_set<int> UniqueElements;
  for (int num : nums) {
    if (UniqueElements.count(num) > 0) {
      return true;
    }
    UniqueElements.insert(num);
  }
  return false;
}

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) cin >> nums[i];
  cout << containsDuplicate(nums) << endl;
  return 0;
}

/*
Question Link:
https://leetcode.com/problems/contains-duplicate/
*/