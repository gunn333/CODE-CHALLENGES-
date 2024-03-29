//! Diameter of a Binary Tree (LeetCode 543)

// Question Link:
// https://leetcode.com/problems/diameter-of-binary-tree/

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

int result = 0;

int maxHeight(TreeNode *root) {
  // Agar root null hai toh height 0 return karange
  if (root == NULL)
    return 0;

  // Left aur right subtree ka height nikalenge
  int left = maxHeight(root->left);
  int right = maxHeight(root->right);

  // current_Diameter = left + right
  // if current_Diameter > result(Maximum Diameter till now) then update result
  result = max(result, left + right);

  // longest path from root to leaf node is max(left, right) + 1 (root node)
  return max(left, right) + 1;
}

int diameterOfBinaryTree(TreeNode *root) {
  maxHeight(root);
  return result;
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  cout << diameterOfBinaryTree(root) << endl;

  return 0;
}
