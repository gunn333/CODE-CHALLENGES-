//! Convert Sorted Array to Binary Search Tree (Leetcode #108)

// Question Link:
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Time complexity: O(n)
TreeNode *sortedArrayToBST(vector<int> &nums) {
  // If the array is empty, return NULL
  if (nums.size() == 0)
    return NULL;
  int n = nums.size();
  int mid_idx = n / 2;
  vector<int> left_half{};
  vector<int> right_half{};
  for (int i = 0; i < n; i++) {
    // agar current index mid_idx se chota hai to left half me push karenge
    if (i < mid_idx) {
      left_half.push_back(nums[i]);
    } else if (i > mid_idx) {
      // agar current index mid_idx se bada hai to right half me push karenge
      right_half.push_back(nums[i]);
    }
  }
  // mid_idx pe jo element hai woh root hoga
  // mid ko root banaya hai because it is height balanced BST
  TreeNode *root = new TreeNode(nums[mid_idx]);
  // left half ko left child banayenge
  root->left = sortedArrayToBST(left_half);
  root->right = sortedArrayToBST(right_half);
  return root;
}
