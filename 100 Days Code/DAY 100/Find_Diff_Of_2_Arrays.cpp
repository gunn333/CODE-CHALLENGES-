//! Find the difference of two arrays (LeetCode 2215)

// Question Link:
// https://leetcode.com/problems/find-the-difference-of-two-arrays/description/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2) {
  // Answer vector
  vector<vector<int>> ans;
  // Sort the arrays as we need to find the difference
  sort(nums1.begin(), nums1.end());
  sort(nums2.begin(), nums2.end());
  // Set to store the elements of the arrays
  set<int> st1, st2;
  for (int i = 0; i < nums1.size(); i++) {
    st1.insert(nums1[i]);
  }
  for (int i = 0; i < nums2.size(); i++) {
    st2.insert(nums2[i]);
  }
  // Vector to store the difference of the two arrays
  vector<int> v1, v2;
  // Find the difference of the two arrays
  // set_difference will find the difference of the two sets
  // inserter will insert the elements in the vector
  // set_difference(st1.begin(), st1.end(), st2.begin(), st2.end(), inserter(v1,
  // v1.begin())); will find the elements in st1 which are not in st2 and insert
  // it in v1
  set_difference(st1.begin(), st1.end(), st2.begin(), st2.end(),
                 inserter(v1, v1.begin()));
  /*
  st1.begin() and st1.end() represent the starting and ending iterators of the
first set (st1). st2.begin() and st2.end() represent the starting and ending
iterators of the second set (st2). inserter(v1, v1.begin()) is an iterator that
specifies where the output elements will be inserted in the container v1.
  */
  set_difference(st2.begin(), st2.end(), st1.begin(), st1.end(),
                 inserter(v2, v2.begin()));
  // Ans mein v1 aur v2 push kara diya
  ans.push_back(v1);
  ans.push_back(v2);
  return ans;
}

int main() {
  // Test case 1
  vector<int> nums1 = {1, 2, 3, 4, 5};
  vector<int> nums2 = {1, 2, 3, 4, 6};
  vector<vector<int>> ans = findDifference(nums1, nums2);
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  // Test case 2
  nums1 = {1, 2, 3, 4, 5};
  nums2 = {1, 2, 3, 4, 5};
  ans = findDifference(nums1, nums2);
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}