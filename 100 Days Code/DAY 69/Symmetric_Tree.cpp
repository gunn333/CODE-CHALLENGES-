//! Symmetric Tree (LeetCode 101)

// Question Link:
// https://leetcode.com/problems/symmetric-tree/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSymmetric(TreeNode *root) {
  if (root == NULL) {
    return true;
  }

  return isSymmetric(root->left, root->right);
}

bool isSymmetric(TreeNode *left, TreeNode *right) {
  // Base cases
  // Base case1 ---> if both the value are NULL then return true
  if (left == NULL && right == NULL) {
    return true;
  }

  // Base case2 ---> if one of the value is NULL then return false
  else if (left == NULL || right == NULL) {
    return false;
  }

  // Base case3 ---> if the value of left and right are not equal then return
  // false
  else if (left->val != right->val) {
    return false;
  }

  // Checks if the left subtree of the left node is equal to the right subtree
  // of the right node and vice versa.
  return isSymmetric(left->left, right->right) &&
         isSymmetric(left->right, right->left);
}