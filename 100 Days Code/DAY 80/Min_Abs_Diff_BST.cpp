//! Minimum Absolute Difference in BST (LeetCode 530)

// Question Link:
// https://leetcode.com/problems/minimum-absolute-difference-in-bst/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int getMinimumDifference(TreeNode *root) {
  int res = INT_MAX;
  TreeNode *prev = NULL;
  inorder(root, prev, res);
  return res;
}

void inorder(TreeNode *root, TreeNode *&prev, int &res) {
  if (root == NULL) {
    return;
  }
  inorder(root->left, prev, res);
  if (prev != NULL) {
    res = min(res, root->val - prev->val);
  }
  prev = root;
  inorder(root->right, prev, res);
}

int main() {
  // Let's create the tree
  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);

  cout << getMinimumDifference(root) << endl;
  return 0;
}