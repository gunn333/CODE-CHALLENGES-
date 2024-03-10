//! Intersection Of Two Arrays (LeetCode 349)

// Question Link:
// https://leetcode.com/problems/intersection-of-two-arrays/

#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
  unordered_set<int> s;
  sort(nums1.begin(), nums1.end());
  sort(nums2.begin(), nums2.end());
  vector<int> v;
  int i = 0, j = 0;
  while (i < nums1.size() && j < nums2.size()) {
    if (nums1[i] == nums2[j]) {
      if (s.count(nums1[i])) {
        i++, j++;
      } else {
        v.push_back(nums1[i]);
        s.insert(nums1[i]);
      }
    } else if (nums1[i] > nums2[j]) {
      j++;
    } else {
      i++;
    }
  }
  return v;
}

int main() {
  vector<int> nums1 = {1, 2, 2, 1};
  vector<int> nums2 = {2, 2};
  vector<int> res = intersection(nums1, nums2);
  for (int i : res) {
    cout << i << " ";
  }
  return 0;
}