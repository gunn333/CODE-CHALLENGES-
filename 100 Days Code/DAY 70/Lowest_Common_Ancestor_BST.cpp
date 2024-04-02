//! Lowest Common Ancestor of a Binary Search Tree (LeetCode 235)

// Question Link:
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

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
  // Property1 of BST: The left subtree of a node contains only nodes with keys
  // less than the node's key.

  if (root->val > p->val && root->val > q->val) {
    return lowestCommonAncestor(root->left, p, q);
  }

  // Property2 of BST: The right subtree of a node contains only nodes with keys
  // greater than the node's key.
  if (root->val < p->val && root->val < q->val) {
    return lowestCommonAncestor(root->right, p, q);
  }

  // If the above conditions are not met then the root is the lowest common
  // ancestor because the root is the node that is common to both the nodes p
  // and q.
  return root;
}

int main() {
  TreeNode *root = new TreeNode(6);
  root->left = new TreeNode(2);
  root->right = new TreeNode(8);
  root->left->left = new TreeNode(0);
  root->left->right = new TreeNode(4);
  root->right->left = new TreeNode(7);
  root->right->right = new TreeNode(9);
  root->left->right->left = new TreeNode(3);
  root->left->right->right = new TreeNode(5);

  TreeNode *p = root->left;
  TreeNode *q = root->left->right;

  TreeNode *result = lowestCommonAncestor(root, p, q);
  cout << result->val << endl;

  return 0;
}