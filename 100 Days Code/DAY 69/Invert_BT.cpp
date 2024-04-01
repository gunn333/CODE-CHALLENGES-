//! Invert a binary tree. (LeetCode 226)

// Question Link:
// https://leetcode.com/problems/invert-binary-tree/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *invertTree(TreeNode *root) {
  if (root == NULL) {
    return NULL;
  }

  // Traverse the tree
  TreeNode *left = invertTree(root->left);
  TreeNode *right = invertTree(root->right);

  // Swap the left and right nodes
  root->left = right;
  root->right = left;

  return root;
}

int main() {
  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->right = new TreeNode(7);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(9);

  TreeNode *inverted = invertTree(root);

  return 0;
}