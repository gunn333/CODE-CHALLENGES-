//! Flatten Binary Tree to Linked List (LeetCode 114)

// Question Link:
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void flatten(TreeNode *root) {
  if (root != NULL)
    preorder(root);
}
TreeNode *head = NULL;
void preorder(TreeNode *node) {

  if (node->right != NULL)
    preorder(node->right);

  if (node->left != NULL)
    preorder(node->left);
  node->left = NULL;

  node->right = head;

  head = node;
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right = new TreeNode(5);
  root->right->right = new TreeNode(6);

  flatten(root);
  while (root != NULL) {
    cout << root->val << " ";
    root = root->right;
  }
  return 0;
}