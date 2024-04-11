//! Count Good Nodes in Binary Tree (LeetCode 1448)

// Question Link:
// https://leetcode.com/problems/count-good-nodes-in-binary-tree/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int goodNodes(TreeNode *root) { return bfs(root, INT_MIN); }

int bfs(TreeNode *root, int maxVal) {
  if (root == NULL) {
    return 0;
  }
  int goodNodes = 0;
  // If the current node value is greater than or equal to the max value then it
  // is a good node
  if (root->val >= maxVal) {
    goodNodes++;
    // Updating the max value to the current node value
    maxVal = root->val;
  }

  goodNodes += bfs(root->left, maxVal);
  goodNodes += bfs(root->right, maxVal);

  return goodNodes;
}