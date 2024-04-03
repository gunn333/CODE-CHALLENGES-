//! Binary Tree Right View (LeetCode 199)

// Question Link:
// https://leetcode.com/problems/binary-tree-right-side-view/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
DFS:
1. Dfs traversal is done in a preorder manner.
*/
vector<int> rightSideView(TreeNode *root) {
  vector<int> result;
  if (root == NULL) {
    return result;
  }
  int level = 0;
  dfs(root, result, level);
  return result;
}

void dfs(TreeNode *root, vector<int> &result, int level) {
  if (root == NULL) {
    return;
  }
  // level == result.size() means that the current node is the rightmost node at
  // the current level so we add it to the result vector.
  if (level == result.size()) {
    result.push_back(root->val);
  }
  // level+1 because we are going to the next level from left and right child of
  // the current node.
  dfs(root->right, result, level + 1);
  dfs(root->left, result, level + 1);
}