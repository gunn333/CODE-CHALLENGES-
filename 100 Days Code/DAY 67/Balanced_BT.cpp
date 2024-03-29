//! Balanced Binary Tree (LeetCode 110)

// Question Link:
// https://leetcode.com/problems/balanced-binary-tree/

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

// We will count the height of the tree and check if the tree is balanced or not
int countHeight(TreeNode *root) {
  if (root == NULL) {
    return 0;
  }
  // Count the height of the left and right subtrees
  int leftHeight = countHeight(root->left);
  int rightHeight = countHeight(root->right);

  // leftHeight and rightHeight will be -1 if the tree is not balanced
  // leftHeight - rightHeight > 1 means the tree is not balanced
  if (leftHeight == -1 || rightHeight == -1 ||
      abs(leftHeight - rightHeight) > 1) {
    return -1;
  }

  // Height of Balanced Tree is the maximum height of left and right subtrees +
  // 1
  return max(leftHeight, rightHeight) + 1;
}
bool isBalanced(TreeNode *root) {
  // A tree with no nodes is balanced
  if (root == NULL) {
    return true;
  }
  // If the height of the tree is -1, then the tree is not balanced
  return countHeight(root) == -1 ? false : true;
}

int main() {
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  cout << isBalanced(root) << endl;

  return 0;
}