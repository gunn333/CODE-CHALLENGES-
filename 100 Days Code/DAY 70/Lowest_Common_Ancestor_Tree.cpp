//! Lowest Common Ancestor of a Binary Tree (LeetCode 236)

// Question Link:
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
  if (root == NULL) {
    return NULL;
  }
  if (root == p || root == q) {
    return root;
  }
  TreeNode *left = lowestCommonAncestor(root->left, p, q);
  TreeNode *right = lowestCommonAncestor(root->right, p, q);
  if (left != NULL && right != NULL) {
    return root;
  }
  if (left == NULL) {
    return right;
  }
  return left;
}

int main() {
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(5);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);
  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(8);
  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(4);

  TreeNode *p = root->left;
  TreeNode *q = root->right;

  TreeNode *result = lowestCommonAncestor(root, p, q);
  cout << result->val << endl;

  return 0;
}