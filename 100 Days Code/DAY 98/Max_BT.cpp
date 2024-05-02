//! Maximum Binary Tree (LeetCode 654)

// Question Link :
// https://leetcode.com/problems/maximum-binary-tree/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) {
    val = x;
    left = NULL;
    right = NULL;
  }
};

TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
  // Base case
  if (nums.size() == 0) {
    return NULL;
  }
  // Find the maximum Index in nums
  int maxIndex = 0;
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] > nums[maxIndex]) {
      maxIndex = i;
    }
  }
  // Create a new TreeNode with the maximum value
  TreeNode *root = new TreeNode(nums[maxIndex]);
  // vector<int> left(size of vector, value to fill)
  vector<int> left(nums.begin(), nums.begin() + maxIndex);
  vector<int> right(nums.begin() + maxIndex + 1, nums.end());
  root->left = constructMaximumBinaryTree(left);
  root->right = constructMaximumBinaryTree(right);
  return root;
}

void printInorder(TreeNode *root) {
  if (root == NULL) {
    return;
  }
  printInorder(root->left);
  cout << root->val << " ";
  printInorder(root->right);
}

int main() {
  vector<int> nums = {3, 2, 1, 6, 0, 5};
  TreeNode *root = constructMaximumBinaryTree(nums);
  printInorder(root);
  return 0;
}