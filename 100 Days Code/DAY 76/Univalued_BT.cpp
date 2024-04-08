//! Univalued Binary Tree (LeetCode 965)

// Question Link:
// https://leetcode.com/problems/univalued-binary-tree/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

bool isUnivalTree(TreeNode *root) {
  if (root == NULL) {
    return true;
  }
  // If root has left child and left child value is not equal to root value
  if (root->left != NULL && root->left->val != root->val) {
    return false;
  }
  // If root has right child and right child value is not equal to root value
  if (root->right != NULL && root->right->val != root->val) {
    return false;
  }
  // Recursively check for left and right child of root node
  bool left = isUnivalTree(root->left);
  bool right = isUnivalTree(root->right);
  // If both left and right are true then return true
  return left && right;
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(1);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(1);
  root->right->right = new TreeNode(1);

  cout << isUnivalTree(root) << endl;
  return 0;
}