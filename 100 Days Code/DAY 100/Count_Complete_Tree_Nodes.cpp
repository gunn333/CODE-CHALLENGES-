//! Count Complete Tree Nodes (LeetCode 222)

// Question Link:
// https://leetcode.com/problems/count-complete-tree-nodes/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) {
    val = x;
    left = right = NULL;
  }
};

int countNodes(TreeNode *root) {
  if (root == NULL) {
    return 0;
  }
  int leftHeight = 0;
  TreeNode *left = root;
  while (left != NULL) {
    leftHeight++;
    left = left->left;
  }
  int rightHeight = 0;
  TreeNode *right = root;
  while (right != NULL) {
    rightHeight++;
    right = right->right;
  }
  if (leftHeight == rightHeight) {
    return pow(2, leftHeight) - 1;
  }
  return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  cout << countNodes(root) << endl;
  return 0;
}