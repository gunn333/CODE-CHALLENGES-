//! Merge 2 binary trees. (LeetCode 617)

// Question Link:
// https://leetcode.com/problems/merge-two-binary-trees/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
  // Base case 1 ---> if root1 is NULL then return root2 as the merged tree
  if (root1 == NULL) {
    return root2;
  }

  // Base case 2 ---> if root2 is NULL then return root1 as the merged tree
  if (root2 == NULL) {
    return root1;
  }

  // root1 value is updated with the sum of root1 and root2 values
  root1->val = root1->val + root2->val;
  // root1 left is updated with the merged left subtree of root1 and root2
  // left
  root1->left = mergeTrees(root1->left, root2->left);
  // root1 right is updated with the merged right subtree of root1 and root2
  root1->right = mergeTrees(root1->right, root2->right);

  // return the merged tree
  return root1;
}

int main() {
  TreeNode *root1 = new TreeNode(1);
  root1->left = new TreeNode(3);
  root1->right = new TreeNode(2);
  root1->left->left = new TreeNode(5);

  TreeNode *root2 = new TreeNode(2);
  root2->left = new TreeNode(1);
  root2->right = new TreeNode(3);
  root2->left->right = new TreeNode(4);
  root2->right->right = new TreeNode(7);

  TreeNode *merged = mergeTrees(root1, root2);

  return 0;
}