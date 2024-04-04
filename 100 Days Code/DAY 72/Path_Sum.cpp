//! Path Sum (LeetCode 112)

// Question Link:
// https://leetcode.com/problems/path-sum/

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

bool hasPathSum(TreeNode *root, int targetSum) {

  if (root == NULL) {
    return false;
  }
  if (root->left == NULL && root->right == NULL && targetSum == root->val) {
    return true;
  }
  return hasPathSum(root->left, targetSum - root->val) ||
         hasPathSum(root->right, targetSum - root->val);
}

int main() {
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(4);
  root->right = new TreeNode(8);
  root->left->left = new TreeNode(11);
  root->left->left->left = new TreeNode(7);
  root->left->left->right = new TreeNode(2);
  root->right->left = new TreeNode(13);
  root->right->right = new TreeNode(4);
  root->right->right->right = new TreeNode(1);
  cout << hasPathSum(root, 22) << endl;
  return 0;
}
