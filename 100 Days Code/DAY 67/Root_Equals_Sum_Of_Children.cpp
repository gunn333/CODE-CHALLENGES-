//! Root Equals Sum Of Children (Leetcode 2236)

// Question Link:
// https://leetcode.com/problems/root-equals-sum-of-children/

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

bool checkTree(TreeNode *root) {
  if (root == NULL) {
    return true;
  }
  int sum = 0;
  if (root->left != NULL) {
    sum += root->left->val;
  }
  if (root->right != NULL) {
    sum += root->right->val;
  }
  if (root->val != sum) {
    return false;
  }
  return true;
}

int main() {
  TreeNode *root = new TreeNode(10);
  root->left = new TreeNode(5);
  root->right = new TreeNode(5);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(3);
  root->right->left = new TreeNode(2);
  root->right->right = new TreeNode(3);

  cout << checkTree(root) << endl;
  return 0;
}