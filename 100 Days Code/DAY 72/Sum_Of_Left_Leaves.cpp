//! Sum Of Left Leaves (LeetCode 404)

// Question Link:
// https://leetcode.com/problems/sum-of-left-leaves/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sumOfLeftLeaves(TreeNode *root) {
  if (root == NULL) {
    return 0;
  }
  // if root has left node child but it further dosent have any children
  if (root->left != NULL && root->left->left == NULL &&
      root->left->right == NULL) {
    return root->left->val + sumOfLeftLeaves(root->right);
  }
  return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}

int main() {
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  cout << sumOfLeftLeaves(root) << endl;

  return 0;
}