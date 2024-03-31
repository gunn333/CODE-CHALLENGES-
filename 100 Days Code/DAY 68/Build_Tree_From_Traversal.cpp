//! Construct Binary Tree from Preorder and Inorder Traversal (Leetcode #105)

// Question Link:
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
  if (preorder.size() == 0) {
    return NULL;
  }
  // root node is the first element of the preorder traversal
  TreeNode *root = new TreeNode(preorder[0]);
  // find the index of the root node in the inorder traversal
  int root_idx = 0;
  for (int i = 0; i < inorder.size(); i++) {
    if (inorder[i] == preorder[0]) {
      root_idx = i;
      break;
    }
  }
  // left subtree of the root node
  vector<int> left_inorder(inorder.begin(), inorder.begin() + root_idx);
  vector<int> left_preorder(preorder.begin() + 1,
                            preorder.begin() + 1 + root_idx);
  root->left = buildTree(left_preorder, left_inorder);
  // right subtree of the root node
  vector<int> right_inorder(inorder.begin() + root_idx + 1, inorder.end());
  vector<int> right_preorder(preorder.begin() + 1 + root_idx, preorder.end());
  root->right = buildTree(right_preorder, right_inorder);
  return root;
}